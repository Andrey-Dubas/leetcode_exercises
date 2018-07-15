#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>

std::string preProcess(std::string s)
{
    int n = s.length();

    if (n == 0) return "^$";

    std::string ret = "^";
    for (int i = 0; i < n; ++i)
    {
        ret += "#" + s.substr(i, 1);
    }

    ret += "#$";
    return ret;
}


std::string longestPalindrome(std::string s)
{
    std::string extendedString = preProcess(s);
    int n = extendedString.length();
    int *P = new int[n];
    memset(P, 0x00, sizeof(int)*n);
    int center = 0, upperBound = 0;

    for (int i = 1; i < n; ++i)
    {

        if (upperBound > 1)
        {
            int i_mirror = center - (i-center);
            P[i] = std::min(upperBound-i, P[i_mirror]);
        }

        while (extendedString[i + 1+P[i]] == extendedString[i - (1+P[i])])
            P[i]++;

        // if palindrome centered at i expand pasr R,
        // adjust center based on expanded palindrome.
        if (i + P[i] > upperBound)
        {
            center = i;
            upperBound = i + P[i];
        }
    }


    // just finding maxlen out of P array
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n-1; ++i)
    {
        if (P[i] > maxLen)
        {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    delete[] P;

    return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
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
