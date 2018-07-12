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
#include <cstring>

using namespace std;

typedef unsigned int uint;


class Solution {
public:

	std::pair<int, int> checkPalindromeForIndex(const char* s, int i, int len)
    {
        std::pair<int, int> result;
        int lower = i;
        int higher = i;
        if (s[i] == s[i+1])
        {
            ++higher;

            while (s[--lower] == s[++higher] && lower >= 0 && higher < len);

            if (higher-lower >= 2) {++lower; --higher;}
            
            result.first = lower;
            result.second = higher-lower+1;
        }
        
        lower = i;
        higher = i;
        
        while (s[--lower] == s[++higher] && lower >= 0 && higher < len);

        if (higher-lower >= 2) {++lower; --higher;}
        
        if (higher-lower+1 > result.second)
        {
            result.first = lower;
            result.second = higher-lower+1;
        }
        return result;
    }   

    string longestPalindrome(string s) {
        int maxLen = 0;
        int offset = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            std::pair<int, int> pair = checkPalindromeForIndex(s.c_str(), i, s.size());
            if (pair.second > maxLen)
            {   
                offset = pair.first;
                maxLen = pair.second;
            }   
        }
        return s.substr(offset, maxLen);
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

    std::string input1  = "ccc";
    std::string output1 = "ccc";

    Solution s;

    CPPUNIT_ASSERT_EQUAL(output, s.longestPalindrome(input));
    CPPUNIT_ASSERT_EQUAL(output1, s.longestPalindrome(input1));
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
