// https://leetcode.com/problems/palindrome-number/description/
//Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
// 
// Example 1:
// 
// Input: 121
// Output: true

#include <string>

using namespace std;

typedef unsigned int uint;

class Solution {
public:
    bool isPalindrome(int x) {
        std::string s = std::to_string(x);

        const char* lower  = s.c_str();
        const char* higher = s.c_str() + s.size()-1;

        while (higher >= lower)
        {
            if (*lower != *higher)
            {
                return false;
            }
            ++lower; --higher;
        }

        return true;
    }
};

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

class Test: public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( Test ); 

    // CPPUNIT_TEST( test1 );
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

    CPPUNIT_ASSERT(s.isPalindrome(121));

}

void Test::test2()
{
    Solution s;

    CPPUNIT_ASSERT(s.isPalindrome(-121) == false);

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
