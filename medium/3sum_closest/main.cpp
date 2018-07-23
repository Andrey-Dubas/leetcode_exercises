// https://leetcode.com/problems/3sum-closest/description/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned int uint;

// Quadratic algorithm
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;

        std::sort(nums.begin(), nums.end());
        int solution = nums[0] + nums[1] + nums[2] - target;

        for (unsigned int i = 0; i < nums.size()-2; ++i)
        {
            int lower = i+1;
            int higher = nums.size()-1;

            while (lower < higher)
            {
                int sum = nums[i] + nums[higher] + nums[lower] - target;
                if (std::abs(sum) <= std::abs(solution))
                {
                    solution = sum;
                }
                if (sum < 0)
                {
                    ++lower;
                }
                else if (sum > 0)
                {
                    --higher;
                }
                else
                {
                    break;
                }
            }
        }

        return solution+target;
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
    std::vector<int> v = {-1, 2, 1, -4};

    CPPUNIT_ASSERT_EQUAL(2, s.threeSumClosest(v, 1));
}

void Test::test2()
{
    Solution s;
    std::vector<int> v = {1,-3,3,5,4,1};

    CPPUNIT_ASSERT_EQUAL(1, s.threeSumClosest(v, 1));

}

void Test::test3()
{
    Solution s;
    std::vector<int> v = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    CPPUNIT_ASSERT_EQUAL(0, s.threeSumClosest(v, 5));
}

int main()
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();
    return 0;
}
