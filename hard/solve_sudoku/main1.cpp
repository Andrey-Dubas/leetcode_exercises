#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <assert.h>

using namespace std;

typedef unsigned int uint;



std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<char>>& chars)
{
    os << std::endl;
    for (size_t i = 0; i < chars.size(); ++i)
    {
        if (!chars[i].empty())
        {
            os << "[\'" << chars[i][0] << "\'";
        }

        for (size_t j = 1; j < chars[i].size(); ++j)
        {
            os << ", [\'" << chars[i][j]  << "\']";
        }
        os << ']' << std::endl;
    }

    return os;
}


struct State
{
    int x, y, digit;
};

std::ostream& operator<<(std::ostream& os, const State& state)
{
    os << "y: " << state.y << ", x: " << state.x << ", digit: " << state.digit;
    return os;
}


class Solution {
public:
    
    bool check(vector<vector<char>>& board, State state)
    {
        int x = state.x, y = state.y;
        bool marked[10]; // (9, false);
        
        bool result = true;
        char prevDigit = board[state.y][state.x];
        board[state.y][state.x] = '.';
        
        memset((void*)marked, 0x00, sizeof(marked));
        for (int i = 0; i < 9; ++i)
        {
            if (board[y][i] == '.') { continue; }
            int digit = board[y][i] - '0';
            marked[digit] = true;
        }
        if (marked[state.digit]) {
            result = false;
        }
        
        
        memset((void*)marked, 0x00, sizeof(marked));
        for (int i = 0; i < 9; ++i)
        {
            if (board[i][x] == '.') { continue; }
            int digit = board[i][x] - '0';
            marked[digit] = true;
        }
        if (marked[state.digit]) {
            result = false;
        }
        
        
        memset((void*)marked, 0x00, sizeof(marked));
        for (int i = 0; i < 9; ++i)
        {
            int curX = x/3*3 + i/3;
            int curY = y/3*3 + i%3;
            if (board[curY][curX] == '.') { continue; }
            int digit = board[curY][curX] - '0';
            marked[digit] = true;
        }
        if (marked[state.digit]) {
            result = false;
        }
        
        board[state.y][state.x] = prevDigit;
        
        return result;
    }

    const State& getNextState(vector<vector<char>>& board, std::vector<State>& states)
    {
        assert(!states.empty());
        State lastState = states.back();
        states.pop_back();
        int digit = lastState.digit + 1;
        for (; digit <= 9; ++digit)
        {
            if (check(board, {lastState.x, lastState.y, digit}))
            {
                lastState.digit = digit;
                board[lastState.y][lastState.x] = digit + '0';
                states.push_back(lastState);
                return states.back();
            }
        }
        
        // no state in a current cell - go back
        board[lastState.y][lastState.x] = '.';
        return getNextState(board, states);
    }

    State findNextCell(vector<vector<char>>& board, const State& lastState)
    {
        int x, y;
        int i;
        for (i = lastState.x+1 + lastState.y*9; i < 81; ++i)
        {
            y = i/9; x = i%9;
            if (board[y][x] == '.')
            {
                break;
            }
        }

        if (i == 81) {return {9, 9, 10};} // THE END!!

        for (int digit = 1; digit <= 9; ++digit)
        {
            if (check(board, {x, y, digit}))
            {
                board[y][x] = digit + '0';
                return {x, y, digit};
            }
        }

        return {-1, -1, -1};
    }
    

    void solveSudoku(vector<vector<char>>& board)
    {
        std::vector<State> states;

        State state = findNextCell(board, {-1, 0, 0});
        states.push_back(state);
        
        while (true)
        {
            State nextCell = findNextCell(board, states.back());

            if (nextCell.x == -1)
            {
                // go back
                getNextState(board, states);
            }
            else if (nextCell.x == 9)
            {
                return;
            }
            else
            {
                states.push_back(nextCell);
            }
        }
    }
};




#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

class Test: public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( Test ); 

    CPPUNIT_TEST( test1 );
    CPPUNIT_TEST( test2 );
    CPPUNIT_TEST( test3 );

    CPPUNIT_TEST_SUITE_END();

public:
    void test1();
    void test2();
    void test3();
};

CPPUNIT_TEST_SUITE_REGISTRATION( Test );

void Test::test1()
{
    std::vector<std::vector<char>> board = 
    {
          {'5' ,'3' ,'.' ,'.' ,'7' ,'.' ,'.' ,'.' ,'.'}
        , {'6' ,'.' ,'.' ,'1' ,'9' ,'5' ,'.' ,'.' ,'.'}
        , {'.' ,'9' ,'8' ,'.' ,'.' ,'.' ,'.' ,'6' ,'.'}
        , {'8' ,'.' ,'.' ,'.' ,'6' ,'.' ,'.' ,'.' ,'3'}
        , {'4' ,'.' ,'.' ,'8' ,'.' ,'3' ,'.' ,'.' ,'1'}
        , {'7' ,'.' ,'.' ,'.' ,'2' ,'.' ,'.' ,'.' ,'6'}
        , {'.' ,'6' ,'.' ,'.' ,'.' ,'.' ,'2' ,'8' ,'.'}
        , {'.' ,'.' ,'.' ,'4' ,'1' ,'9' ,'.' ,'.' ,'5'}
        , {'.' ,'.' ,'.' ,'.' ,'8' ,'.' ,'.' ,'7' ,'9'}
    };

    std::vector<std::vector<char>> expected = 
    {
          {'5' ,'3' ,'4' ,'6' ,'7' ,'8' ,'9' ,'1' ,'2'}
        , {'6' ,'7' ,'2' ,'1' ,'9' ,'5' ,'3' ,'4' ,'8'}
        , {'1' ,'9' ,'8' ,'3' ,'4' ,'2' ,'5' ,'6' ,'7'}
        , {'8' ,'5' ,'9' ,'7' ,'6' ,'1' ,'4' ,'2' ,'3'}
        , {'4' ,'2' ,'6' ,'8' ,'5' ,'3' ,'7' ,'9' ,'1'}
        , {'7' ,'1' ,'3' ,'9' ,'2' ,'4' ,'8' ,'5' ,'6'}
        , {'9' ,'6' ,'1' ,'5' ,'3' ,'7' ,'2' ,'8' ,'4'}
        , {'2' ,'8' ,'7' ,'4' ,'1' ,'9' ,'6' ,'3' ,'5'}
        , {'3' ,'4' ,'5' ,'2' ,'8' ,'6' ,'1' ,'7' ,'9'}
    };

    Solution s;
    s.solveSudoku(board);

    CPPUNIT_ASSERT_EQUAL(expected, board);

}

void Test::test2()
{

}

void Test::test3()
{

}

int main()
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();
    return 0;
}
