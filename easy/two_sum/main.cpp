// https://leetcode.com/problems/two-sum/description/

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (hash.find(target-nums[i]) != hash.end())
            {
                std::vector<int> result = {hash[target-nums[i]], i};
                return result;
            }
            hash[nums[i]] = i;
        }

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
}

void Test::test2()
{
    std::vector<int> v = {2,7,11,15};
    int sum = 9;
    Solution s;
    std::vector<int> expectedSol = {0, 1};
    std::vector<int> solution = s.twoSum(v, sum);

    CPPUNIT_ASSERT_EQUAL(size_t(2), solution.size());
    CPPUNIT_ASSERT_EQUAL(expectedSol[0], solution[0]);
    CPPUNIT_ASSERT_EQUAL(expectedSol[1], solution[1]);
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
