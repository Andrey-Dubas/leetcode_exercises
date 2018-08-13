// https://leetcode.com/problems/generate-parentheses/description/
//
//  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:
// 
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

typedef unsigned int uint;

class Solution {
public:

    struct StringState
    {
        std::string string;
        int open;
        int close;
    };

    std::vector<std::string> generateParenthesis(int n) {
        StringState iniState = {"", n, 0};
        std::vector<StringState> result = {iniState};

        while (result[0].open || result[0].close)
        {
            std::vector<StringState> next;

            for (StringState& state: result)
            {
                if (state.open)
                {
                    next.push_back(state);
                    next.back().string += '(';
                    next.back().open--;
                    next.back().close++;
                }
                if (state.close)
                {
                    next.push_back(state);
                    next.back().string += ')';
                    next.back().close--;
                }
            }

            std::swap(next, result);
        }

        std::vector<std::string> strs;

        for (const StringState& state: result)
        {
            strs.push_back(state.string);
        }

        return strs;
    }

};

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& strs)
{
    os << "{";
    if (!strs.empty())
    {
        os << strs[0];

        for (unsigned int i = 1; i < strs.size(); ++i)
        {
            os << ", " << strs[i];
        }
    }
    os << "}";

    return os;
}

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
    Solution s;
    std::vector<std::string> result = 
    {
        "((()))",
        "(()())",
        "(())()",
        "()(())",
        "()()()"
    };

    CPPUNIT_ASSERT_EQUAL(result, s.generateParenthesis(3));

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
