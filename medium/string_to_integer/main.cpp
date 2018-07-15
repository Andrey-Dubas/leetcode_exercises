// https://leetcode.com/problems/string-to-integer-atoi/description/
//
//Implement atoi which converts a string to an integer.

// The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
// 
// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
// 
// If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
// 
// If no valid conversion could be performed, a zero value is returned.
// 
// Note:
// 
//     Only the space character ' ' is considered as whitespace character.
//     Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
// 
// Example 1:
// 
// Input: "42"
// Output: 42
// 
// Example 2:
// 
// Input: "   -42"
// Output: -42
// Explanation: The first non-whitespace character is '-', which is the minus sign.
//              Then take as many numerical digits as possible, which gets 42.
// 
// Example 3:
// 
// Input: "4193 with words"
// Output: 4193
// Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
// 
// Example 4:
// 
// Input: "words and 987"
// Output: 0
// Explanation: The first non-whitespace character is 'w', which is not a numerical
//              digit or a +/- sign. Therefore no valid conversion could be performed.
// 
// Example 5:
// 
// Input: "-91283472332"
// Output: -2147483648
// Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
//              Thefore INT_MIN (−231) is returned.



#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

typedef unsigned int uint;

class Solution {
public:
    int myAtoi(string s) {
        int i = -1;
        int result = 0;
        while (s[++i] == ' ');

        int sign = 0;
        if (s[i] == '-')
        {
            sign = 1;
            ++i;
        }
        else if (s[i] == '+') ++i;


        while (s[i] >= '0' && s[i] <= '9')
        {
            int lastDigit = (int)s[i]-(int)'0';
            if (sign == 1) lastDigit = -lastDigit;

            if ((result == std::numeric_limits<int32_t>::max()/10 && lastDigit > std::numeric_limits<int32_t>::max()%10)
               || result > std::numeric_limits<int32_t>::max()/10)
            {
                return std::numeric_limits<int32_t>::max();
            }

            if ((result == std::numeric_limits<int32_t>::min()/10 && lastDigit < std::numeric_limits<int32_t>::min()%10)
               || result < std::numeric_limits<int32_t>::min()/10)
            {
                return std::numeric_limits<int32_t>::min();
            }
            result = result*10 + lastDigit;
            ++i;
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

    CPPUNIT_TEST( test2 );
    CPPUNIT_TEST( test3 );

    CPPUNIT_TEST_SUITE_END();

public:
    void vector2NumTest();
    void test2();
    void test3();
};

CPPUNIT_TEST_SUITE_REGISTRATION( Test );


void Test::test2()
{
    Solution s;

    std::string input1 = "42";
    int output1 = 42;
    CPPUNIT_ASSERT_EQUAL(output1, s.myAtoi(input1));

    std::string input2 = " -42";
    int output2 = -42;
    CPPUNIT_ASSERT_EQUAL(output2, s.myAtoi(input2));
    
    std::string input3 = "4193 with words";
    int output3 = 4193;
    CPPUNIT_ASSERT_EQUAL(output3, s.myAtoi(input3));

    std::string input4 = "words with 875";
    int output4 = 0;
    CPPUNIT_ASSERT_EQUAL(output4, s.myAtoi(input4));

    std::string input5 = "-9123456674578";
    int output5 = std::numeric_limits<int32_t>::min();
    CPPUNIT_ASSERT_EQUAL(output5, s.myAtoi(input5));

    std::string input6 = "-2147483648";
    int output6 = std::numeric_limits<int32_t>::min();
    CPPUNIT_ASSERT_EQUAL(output6, s.myAtoi(input6));

    std::string input7 = "-2147483649";
    int output7 = std::numeric_limits<int32_t>::min();
    CPPUNIT_ASSERT_EQUAL(output7, s.myAtoi(input7));

    std::string input8 = "-2147483646";
    int output8 = -2147483646;
    CPPUNIT_ASSERT_EQUAL(output8, s.myAtoi(input8));

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
