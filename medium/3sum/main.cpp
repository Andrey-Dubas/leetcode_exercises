#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned int uint;

// bool operator==(const std::vector<int>& v1, const std::vector<int>& v2)
// {
//     for (uint i = 0; i < v1.size(); ++i)
//     {
//         if (v1[i] != v2[i])
//         {
//             return false;
//         }
//     }
//     return true;
// }

// Quadratic algorithm
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector< std::vector<int> > result;
        std::sort(nums.begin(), nums.end());

        for (uint i = 0; i < nums.size(); ++i)
        {
            int sum2 = -nums[i];

            int lower = i+1;
            int high = nums.size()-1;

            while (high > lower)
            {
                if (nums[lower] + nums[high] > sum2)
                {
                    --high;
                }
                else if (nums[lower] + nums[high] < sum2)
                {
                    ++lower;
                }
                else
                {
                    std::vector<int> sol = {nums[i], nums[lower], nums[high]};
                    if (std::find(result.begin(), result.end(), sol) == result.end())
                    {
                        result.push_back(sol);
                    }
                    --high;
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
