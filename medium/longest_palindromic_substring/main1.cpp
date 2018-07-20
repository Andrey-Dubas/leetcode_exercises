// https://leetcode.com/problems/longest-palindromic-substring/description/
//
// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
//
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
// Example 2:
//
// Input: "cbbd"
// Output: "bb"

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned int uint;

class Solution {
public:

    struct Offset
    {
        uint offset;
        enum Order
        {
            DIRECT,
            REVERSE
        } type;
        int refToInitialPos;
    };

    void indexedSort(const std::string& s, std::vector<int>& initialToSorted, std::vector<Offset>& sortedToInitial)
    {
        const char* str = s.c_str();
        std::vector<int> offsets(256, 0);

        for (int i = 0; i < s.size(); ++i)
        {
            ++offsets[(int)s[i]+1];
        }

        for (int i = 0; i < offsets.size()-1; ++i)
        {
            offsets[i+1] += offsets[i];
        }

        for (int i = 0; i < s.size(); ++i)
        {
            initialToSorted[i] = offsets[i];

            sortedToInitial[offsets[i]].refToInitialPos = i;
            sortedToInitial[offsets[i]].offset = offsets[i];

            ++offsets[i];
        }
        
    }

    void sort(const std::string& s, int index, int lowerBound, int higherBound, std::vector<int>& initialToSorted, std::vector<Offset>& sortedToInitial)
    {
        


    }

    void sort(const std::string& s, std::vector<int>& initialToSorted, std::vector<int>& sortedToInitial)
    {
        const char* str = s.c_str();
        

    }

    std::string longestPalindrome(std::string s) {
        std::string result;


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

void Test::test1()
{
    std::string input  = "cbbd";
    std::string output = "bb";

    Solution s;

    CPPUNIT_ASSERT_EQUAL(output, s.longestPalindrome(input));
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
