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

    std::vector<int> polinomLength(extendedString.size(), 0);

    int center = 0;
    int upperBound = 0;

    for (int i = 0; i < extendedString.size(); ++i)
    {
        if (upperBound > 1)
        {
            int mirroredIndex = i - 2*center;
            polinomLength[i] = std::min(upperBound-i, polinomLength[mirroredIndex]);
        }

        while (extendedString[i - polinomLength[i] - 1] == extendedString[i + polinomLength[i] + 1])
        {
            polinomLength[i]++;
        }

        if (i + polinomLength[i] > upperBound)
        {
            center = i;
            upperBound = center + polinomLength[i];
        }

    }

    int maxLen = 0;
    int centerLen = 0;

    for (int i = 0; i < polinomLength.size(); ++i)
    {
        if (polinomLength[i] > maxLen)
        {
            maxLen = polinomLength[i];
            centerLen = i;
        }
    }

    return s.substr((centerLen - maxLen-1)/2, maxLen);


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
