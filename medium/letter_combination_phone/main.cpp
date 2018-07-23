// https://leetcode.com/problems/string-to-integer-atoi/description/
//
//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
// ---  abc def
//  1    2   3
//
// ghi  jkl mno
//  4    5   6
//
// pqrs fuv wxyz
//  7    8   9



#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

typedef unsigned int uint;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::vector<int> iterators;
        std::string singleCombination;
        std::vector<std::string> result;
        std::vector<int> digitNums = {3, 3, 3, 3, 3, 4, 3, 4};
        std::vector<char> digitOffset = {'a'};

        if (digits.empty())
        {
            return result;
        }

        for (int i = 1; i < digitNums.size(); ++i)
        {
            digitOffset.push_back(digitOffset.back() + digitNums[i-1]);
        }

        for (int i = 0; i < digits.size(); ++i)
        {
            iterators.push_back(digitOffset[digits[i]-'2']);
            singleCombination += digitOffset[digits[i]-'2'];
        }

        int counter = 0;

        std::vector<int> mods = {1};

        for (int i = 0; i < digits.size(); ++i)
        {
            mods.push_back(mods[mods.size()-1]*digitNums[digits[i]-'2']);
        }

        while (counter < mods[mods.size()-1])
        {
            for (int i = 0; i < iterators.size(); ++i)
            {
                if (counter % mods[i+1] == 0)
                {
                    singleCombination[i] = iterators[i];
                }
                else
                {
                    singleCombination[i] = (iterators[i] + (counter / mods[i]) % digitNums[digits[i]-'2']);
                }
            }

            result.push_back(singleCombination);
            ++counter;
        }

        return result;
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


void Test::test2()
{
    Solution s;

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
