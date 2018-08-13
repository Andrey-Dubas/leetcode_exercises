// https://leetcode.com/problems/two-sum/description/

#include <unordered_map>
#include <vector>

#include <cstdlib>
#include <limits>

using namespace std;

class Solution {
public:
    int32_t divide (int dividend, int divisor)
    {
        // if   (divisor < std::numeric_limits<int32_t>::min() 
        //      || divisor > std::numeric_limits<int32_t>::max())
        // {
        //     return 0;
        // }

        if (dividend < 0)
        {
            while (dividend < std::numeric_limits<int32_t>::min())
            {
                dividend -= std::numeric_limits<int32_t>::min();
                dividend++;
            }
        }
        else
        {

            while (dividend > std::numeric_limits<int32_t>::max())
            {
                dividend -= std::numeric_limits<int32_t>::max();
                dividend--;
            }
        }

        int result = 0;
        if (dividend == std::numeric_limits<int32_t>::min())
        {
            if (divisor == -1)
            {
                return std::numeric_limits<int32_t>::max();
            }

            if (divisor == 1)
            {
                return std::numeric_limits<int32_t>::min();
            }

            if (divisor > 0)
            {
                dividend += divisor;
                --result;
            }

            if (divisor < 0)
            {
                dividend -= divisor;
                ++result;
            }

        }

        const int const_mul = 10000;
        int mul = 0;

        int divisor10000 = 0;
        for (int i = 0; i < const_mul; ++i)
        {
            divisor10000 += divisor; 
            ++mul;
            if (  (divisor10000 < std::numeric_limits<int32_t>::min() + std::abs(divisor))
               || (divisor10000 > std::numeric_limits<int32_t>::max() - std::abs(divisor)))
            {
                break;
            }
        }

        if (divisor == std::numeric_limits<int32_t>::min())
        {
            if (dividend == std::numeric_limits<int32_t>::min())
            {
                return result + 1;
            }
            else
            {
                return result;
            }
        }

        if ((dividend < 0 && divisor < 0) || (dividend >= 0 && divisor >= 0))
        {
            if (mul)
            {
                while (std::abs(dividend) >= std::abs(divisor) * mul)
                {
                    dividend -= divisor10000;
                    result += mul;
                }
            }

            while (std::abs(dividend) >= std::abs(divisor))
            {
                dividend -= divisor;
                ++result;
            }
        }
        else
        {
            if (mul)
            {
                while (std::abs(dividend) >= std::abs(divisor) * mul)
                {
                    dividend += divisor10000;
                    result -= mul;
                }
            }


            while (std::abs(dividend) >= std::abs(divisor))
            {
                dividend += divisor;
                --result;
            }
        }
        return result;
    }
};

int32_t divide(int dividend, int divisor)
{
    Solution s;
    return s.divide(dividend, divisor);
}


#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

class Test: public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( Test ); 

    CPPUNIT_TEST( test1 );
    CPPUNIT_TEST( test2 );
    CPPUNIT_TEST( test3 );
    CPPUNIT_TEST( test4 );
    CPPUNIT_TEST( test5 );
    CPPUNIT_TEST( test6 );
    CPPUNIT_TEST( test7 );
    CPPUNIT_TEST( test8 );
    CPPUNIT_TEST( test9 );

    CPPUNIT_TEST_SUITE_END();

public:
    void test1();
    void test2();
    void test3();
    void test4();
    void test5();
    void test6();
    void test7();
    void test8();
    void test9();
};

CPPUNIT_TEST_SUITE_REGISTRATION( Test );

void Test::test1()
{
    CPPUNIT_ASSERT_EQUAL(3, divide(10, 3));
}

void Test::test2()
{
    CPPUNIT_ASSERT_EQUAL(-2, divide(7, -3));
}

void Test::test3()
{
    CPPUNIT_ASSERT_EQUAL(std::numeric_limits<int32_t>::max(), divide(std::numeric_limits<int32_t>::min(), -1));
}

void Test::test4()
{
    CPPUNIT_ASSERT_EQUAL(std::numeric_limits<int32_t>::min(), divide(std::numeric_limits<int32_t>::min(), 1));
}

void Test::test5()
{
    CPPUNIT_ASSERT_EQUAL(std::numeric_limits<int32_t>::min()/2, divide(std::numeric_limits<int32_t>::min(), 2));
}

void Test::test6()
{
    CPPUNIT_ASSERT_EQUAL(715827882, divide(std::numeric_limits<int32_t>::min(), -3));
}

void Test::test7()
{
    CPPUNIT_ASSERT_EQUAL(0, divide(-1006986286, -2145851451));
}

void Test::test8()
{
    CPPUNIT_ASSERT_EQUAL(0, divide(-1010369383, -2147483648));
}

void Test::test9()
{
    CPPUNIT_ASSERT_EQUAL(1, divide(-2147483648, -2147483648));
}

int main()
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();
    return 0;
}
