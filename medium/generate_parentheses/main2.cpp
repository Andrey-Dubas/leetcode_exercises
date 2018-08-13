#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned int uint;

// Quadratic algorithm
class Solution {
public:
    typedef std::vector<int> Vec;

    vector<Vec> threeSum(vector<int>& nums) {
        std::vector<Vec> result;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < int(nums.size())-2; ++i)
        {
            int lower = i+1;
            int higher = nums.size()-1;

            int sum2 = -nums[i];

            while (higher > lower)
            {
                if (nums[lower] + nums[higher] > sum2)
                {
                    --higher;
                }
                else if (nums[lower] + nums[higher] < sum2)
                {
                    ++lower;
                }
                else
                {
                    Vec solution = {nums[i], nums[lower], nums[higher]};
                    if (std::find(result.begin(), result.end(), solution) == result.end())
                    {
                        result.push_back(solution);
                    }
                    ++lower;
                }
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
    std::vector<int> v = {-1,0,1,2,-1,-4};
    auto solutions = s.threeSum(v);
    for (auto sol: solutions)
    {
        for (auto num: sol)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

void Test::test2()
{
    Solution s;
    std::vector<int> v;
    auto solutions = s.threeSum(v);
    for (auto sol: solutions)
    {
        for (auto num: sol)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
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
    auto solutions = s.threeSum(v);
    for (auto sol: solutions)
    {
        for (auto num: sol)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();
    return 0;
}
