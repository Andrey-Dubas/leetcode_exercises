#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef unsigned int uint;

class Solution {
public:
    typedef std::pair<int, std::pair<int, int>> Sum;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::vector<Sum> pairs;
        
        std::vector<std::vector<int>> indexes;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i+1; j < nums.size(); ++j)
            {
                pairs.push_back(std::make_pair(nums[i] + nums[j], std::make_pair(i, j)));
            }
        }
        
        std::unordered_multimap<int, std::pair<int, int>> passedElements;
        
        for (int i = 0; i < pairs.size(); ++i)
        {
            int requiredSum = target - pairs[i].first;
            
            auto found = passedElements.find(requiredSum);
            
            while (found != passedElements.end() && found->first == requiredSum)
            {
                std::vector<int> solution = {found->second.first, found->second.second
                                            ,pairs[i].second.first, pairs[i].second.second};
                ++found;
                std::sort(solution.begin(), solution.end());
                
                bool repeated = false;
                for (int i = 0; i < solution.size()-1; ++i)
                {
                    if (solution[i] == solution[i+1])
                    {
                        repeated = true;
                    }
                }
                
                if (repeated == true) continue;
                
                if (std::find(indexes.begin(), indexes.end(), solution) == indexes.end())
                {
                    indexes.push_back(solution);
                }
                
            }
            passedElements.insert(pairs[i]);
        }
        
        std::vector<std::vector<int>> result;
        
        for (std::vector<int>& i: indexes)
        {
            std::vector<int> solution = {nums[i[0]], nums[i[1]], nums[i[2]], nums[i[3]]};
            std::sort(solution.begin(), solution.end());
            if (std::find(result.begin(), result.end(), solution) == result.end())
            {
                result.push_back(solution);
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
    std::vector<int> v = {1, 0, -1, 0, -2, 2};
    auto solutions = s.fourSum(v, 0);

    CPPUNIT_ASSERT_EQUAL(size_t(3), solutions.size());
}

void Test::test2()
{
    Solution s;
    std::vector<int> v = {-3,-2,-1,0,0,1,2,3};
    auto solutions = s.fourSum(v, 0);

    CPPUNIT_ASSERT_EQUAL(size_t(8), solutions.size());

}

void Test::test3()
{
    Solution s;
    std::vector<int> v = {-5, 5, 4, -3, 0, 0, 4, -2};
    auto solutions = s.fourSum(v, 4);

    CPPUNIT_ASSERT_EQUAL(size_t(2), solutions.size());
}

int main()
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();
    return 0;
}
