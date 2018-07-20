// https://leetcode.com/problems/integer-to-roman/description/
//
//
//Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
//
//Symbol       Value
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//
//For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
//
//Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
//
//    I can be placed before V (5) and X (10) to make 4 and 9. 
//        X can be placed before L (50) and C (100) to make 40 and 90. 
//            C can be placed before D (500) and M (1000) to make 400 and 900.
//
//            Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
//
//            Example 1:
//
//            Input: 3
//            Output: "III"
//
//            Example 2:
//
//            Input: 4
//            Output: "IV"
//
//            Example 3:
//
//            Input: 9
//            Output: "IX"
//
//            Example 4:
//
//            Input: 58
//            Output: "LVIII"
//            Explanation: C = 100, L = 50, XXX = 30 and III = 3.
//
//            Example 5:
//
//            Input: 1994
//            Output: "MCMXCIV"
//            Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

typedef unsigned int uint;

class Solution {
public:
    string intToRoman(int num) {
        std::vector<int>  nums  = {1000, 500, 100, 50,  10,  5,    1};
        std::vector<char> chars = {'M',  'D', 'C', 'L', 'X', 'V', 'I'};
        
        std::string result;
        for (int i = 0; i < nums.size(); ++i)
        {
            int repeats = num / nums[i];
            num %= nums[i];
            for (int j = 0; j < repeats; ++j)
            {
                result += chars[i];
            }
            
            if (i % 2 == 0 && nums[i] != 1 && num >= nums[i+2]*9) // 1000, 100, 10
            {
                result += chars[i+2];
                result += chars[i];
                num %= nums[i+2];
            }
            
            if (i % 2 == 1 && num >= nums[i+1]*4) // 500, 50, 5
            {
                result += chars[i+1];
                result += chars[i];
                num %= nums[i+1];
            }
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
    CPPUNIT_TEST( test4 );

    CPPUNIT_TEST_SUITE_END();

public:
    void test1();
    void test2();
    void test3();
    void test4();
};

CPPUNIT_TEST_SUITE_REGISTRATION( Test );

void Test::test1()
{
    Solution s;

    std::string r = "III";
    CPPUNIT_ASSERT_EQUAL(r, s.intToRoman(3));
}

void Test::test2()
{
    Solution s;

    std::string r = "IV";
    CPPUNIT_ASSERT_EQUAL(r, s.intToRoman(4));
}

void Test::test3()
{
	Solution s;

    std::string r = "IX";
    CPPUNIT_ASSERT_EQUAL(r, s.intToRoman(9));
}

void Test::test4()
{
	Solution s;

    std::string r = "XXXIX";
    CPPUNIT_ASSERT_EQUAL(r, s.intToRoman(39));
}

int main()
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();
    return 0;
}
