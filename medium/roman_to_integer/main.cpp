// https://leetcode.com/problems/roman-to-integer/description/
//

#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

typedef unsigned int uint;

class Solution {
public:
    string intToRoman(int num) {
    	std::vector<char> chars = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        std::vector<int> nums =  {1000, 500, 100,  50,  10,   5,  1};
        int stringIterator = 0;
        int result = 0;
        for (int i = 0; i < chars.size(); ++i)
        {
            if (i%2 == 0 && i != 0)
            {
                if (s[stringIterator] == chars[i] && s[stringIterator+1] == chars[i-2])
                {
                    result += nums[i-2] - nums[i];
                    stringIterator += 2;
                }
                
                if (s[stringIterator] == chars[i] && s[stringIterator+1] == chars[i-1])
                {
                    result += nums[i-1] - nums[i];
                    stringIterator += 2;
                }
            }
            
            while (s[stringIterator] == chars[i])
            {
                result += nums[i];
                ++stringIterator;
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
