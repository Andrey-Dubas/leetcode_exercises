// https://leetcode.com/problems/container-with-most-water/description/
//
// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container and n is at least 2.

#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& heights) {

        int currentArea = 0;
        int lower = 0;
        int higher = heights.size()-1;

        while (higher > lower)
        {
            int area = (higher - lower) * std::min(heights[lower], heights[higher]);

            currentArea = std::max(currentArea, area);

            if (heights[higher] > heights[lower]) ++lower;
            else                                --higher;
        }

        return currentArea;
        
    }
};


#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

class Test: public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( Test ); 

    CPPUNIT_TEST( vector2NumTest );
    CPPUNIT_TEST( test2 );
    CPPUNIT_TEST( test3 );

    CPPUNIT_TEST_SUITE_END();

public:
    void vector2NumTest();
    void test2();
    void test3();
};

CPPUNIT_TEST_SUITE_REGISTRATION( Test );

void Test::vector2NumTest()
{
    std::vector<int> h = {1, 1};
    Solution s;

    CPPUNIT_ASSERT_EQUAL(1, s.maxArea(h));

}

void Test::test2()
{
    std::vector<int> h = {1, 10, 3, 3, 5, 10, 15, 3};
    Solution s;

    CPPUNIT_ASSERT_EQUAL(50, s.maxArea(h));

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
