#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>

std::string preProcess(std::string s)
{
    std::string result = "^";

    if (!s.empty())
    {
        for (char ch: s)
        {
            result += "#" + ch;
        }
        result += "#";
    }
    result += "$";

    return result;
}


std::string longestPalindrome(std::string s)
{
    std::string extendedString = preProcess(s);
    std::vector<int> palindromeLen(s.size(), 0);

    int center = 0;
    int upperBound = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        if (upperBound > 1)
        {
            int mirroredIndex = 2*center - i;
            palindromeLen[i] = std::min(palindromeLen[mirroredIndex], upperBound-1);
        }

        while (s[i - palindromeLen[i]-1] == s[i + palindromeLen[i]+1])
        {
            palindromeLen[i]++;
        }

        if (i + palindromeLen[i] > upperBound)
        {
            center = i;
            upperBound = i + palindromeLen[i];
        }
    }

    int maxLen = 0;
    int maxPos = 0;

    for (int i = 0; i < palindromeLen.size(); ++i)
    {
        if (palindromeLen[i] > maxLen)
        {
            maxPos = i;
            maxLen = palindromeLen[i];
        }
    }

    return s.substr((maxPos-maxLen-1)/2, maxLen);

}


#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

class Test: public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( Test ); 

    CPPUNIT_TEST( test1 );
    CPPUNIT_TEST( preProcessTest );
    CPPUNIT_TEST( test3 );

    CPPUNIT_TEST_SUITE_END();

public:
    void test1();
    void preProcessTest();
    void test3();
};

CPPUNIT_TEST_SUITE_REGISTRATION( Test );

void Test::test1()
{
    std::string input  = "cbbd";
    std::string output = "bb";

    std::string input1  = "ccc";
    std::string output1 = "ccc";


    CPPUNIT_ASSERT_EQUAL(output, longestPalindrome(input));
    CPPUNIT_ASSERT_EQUAL(output1, longestPalindrome(input1));
}

void Test::preProcessTest()
{
    std::string input  = "cbbd";
    std::string output = "^#c#b#b#d#$";

    CPPUNIT_ASSERT_EQUAL(output, preProcess(input));

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
