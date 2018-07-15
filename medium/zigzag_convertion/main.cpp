// https://leetcode.com/problems/zigzag-conversion/description/
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
// 
// P   A   H   N
// A P L S I I G
// Y   I   R
// 
// And then read line by line: "PAHNAPLSIIGYIR"
// 
// Write the code that will take a string and make this conversion given a number of rows:
// 
// string convert(string s, int numRows);
// 
// Example 1:
// 
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// 
// Example 2:
// 
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// 
// P     I    N
// A   L S  I G
// Y A   H R
// P     I



#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

typedef unsigned int uint;

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 0)
        {
            return "";
        }
        if (numRows == 1)
        {
            return s;
        }
        std::string result;
        int step = (numRows-1)*2;
        for (int i = 0; i < s.size(); i+= step)
        {
            result += s[i];
        }

        for (int i = 1; i < numRows-1; ++i)
        {
            for (int j = 0; j+i < s.size(); j+= step)
            {
                result += s[j+i];
                if (j+(step-i) < s.size())
                {
                    result += s[j+(step-i)];
                }
            }
        }

        for (int i = numRows-1; i < s.size(); i+= step)
        {
            result += s[i];
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
    std::string input =  "012101210121012";
    std::string output = "000011111112222";

    Solution s;

    CPPUNIT_ASSERT_EQUAL(s.convert(input, 3), output);

    
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
