#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>


std::string preProcess(const std::string& s)
{
    std::string result = "^";

    for (int i = 0; i < s.size(); ++i)
    {
        result += "#" + s.substr(i, 1);
    }

    result += "#$";

    return result;
}

std::string longestPalindrome(std::string s)
{
    std::string extendedString = preProcess(s);

    int center = 0;
    int upperBound = 0;
    std::vector<int> polinomeLen(extendedString.size(), 0);


    for (int i = 0; i < extendedString.size(); ++i)
    {
        if (upperBound > 1)
        {
            int mirroredIndex = i - 2*center;
            polinomeLen[i] = std::min(polinomeLen[mirroredIndex], upperBound-i);
        }

        while (extendedString[i + polinomeLen[i]+1] == extendedString[i - polinomeLen[i]-1])
        {
            polinomeLen[i]++;
        }

        if (polinomeLen[i] + i > upperBound)
        {
            center = i;
            upperBound = center + polinomeLen[i];
        }
    }



    int maxLen = 0;
    int position = 0;
    for (int i = 0; i < polinomeLen.size(); ++i)
    {
        if (polinomeLen[i] > maxLen)
        {
            maxLen = polinomeLen[i];
            position = i;
        }
    }

    return s.substr((position-maxLen)/2, maxLen);
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

void Test::test1() { std::string input  = "cbbd";
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
