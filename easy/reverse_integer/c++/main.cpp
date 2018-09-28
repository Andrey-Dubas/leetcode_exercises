// https://leetcode.com/problems/reverse-integer/description/
//
//Given a 32-bit signed integer, reverse digits of an integer.
// 
// Example 1:
// 
// Input: 123
// Output: 321
// 
// Example 2:
// 
// Input: -123
// Output: -321
// 
// Example 3:
// 
// Input: 120
// Output: 21
// 
// Note:
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.


#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <limits>

using namespace std;

typedef unsigned int uint;


class Solution {
public:

    int reverse(int x) {
        int result = 0;

        if (x == numeric_limits<int32_t>::min())
        {
            x = 0;
        }

        int sign = x < 0;
        do
        {
            if (std::abs(result) > numeric_limits<int32_t>::max()/10
               || (std::abs(result) == numeric_limits<int32_t>::max()/10 && x%10 == numeric_limits<int32_t>::max()%10) )
            {
                return 0;
            }
            result = result*10 + x%10;
            x/=10;
        } while (x != 0);

        if (result == numeric_limits<int32_t>::min())
        {
            result = 0;
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

void Test::test1()
{
    Solution s;
    CPPUNIT_ASSERT_EQUAL(321, s.reverse(123));
}

void Test::test2()
{
    Solution s;
    CPPUNIT_ASSERT_EQUAL(0, s.reverse(-1563847412));

}

void Test::test3()
{
    Solution s;
    CPPUNIT_ASSERT_EQUAL(-321, s.reverse(-123));
}

int main()
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();
    return 0;
}
