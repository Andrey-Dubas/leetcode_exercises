#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        if (nums.size() == 0) { return -1; }
        if (nums.size() == 1) { return target == nums[0]? 0: -1; }

        int baseline = nums[0];
        int len = nums.size();
        int low = 0, high = len-1;

        if (nums[0] < nums[1] && nums[0] <= nums[len-1]) { }
        else if (nums[len-1] < nums[0] && nums[len-1] <= nums[len-2]) {}
        else
        {
        do
        {

            int middle = (high+low)/2;
            if (nums[middle] < baseline) {high = middle;}
            else if (nums[middle] > baseline) {low = middle+1;}
            else
            {
                int prevMiddle = (middle-1)%len;
                if (nums[prevMiddle] == baseline)
                {
                    high = prevMiddle;
                }
                else { low = middle; break;}
            }
        } while (nums[low] >= nums[(low-1+len)%len]);
        }
        int minIndex = nums[high] > nums[low] ? low : high;

        // return minIndex;
        low = 0; high = len-1;

        if (target >= baseline)
        {
            high = (minIndex-1+len)%len;
        }
        else
        {
            low = minIndex;
        }

        //return minIndex;

        //std::cout << std::endl << "high: " << high << ", low: " << low << std::endl;
        do
        {
            int middle = (high+low)/2;
            // std::cout << middle << " " << nums[middle] << "   ";
            if      (nums[middle] > target) { high = middle-1;}
            else if (nums[middle] < target) { low  = middle+1;}
            else {return middle;}
            if (high == low)
            {
                if (nums[high] == target) { return high;}
                else {return -1;}
            }
        } while (high >= low);

        return -1;
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
    std::vector<int> v = {4, 5, 6, 7, 0, 1, 2};

    CPPUNIT_ASSERT_EQUAL(4, s.search(v, 0));
}

void Test::test2()
{
    Solution s;
    std::vector<int> v = {1,3};

    CPPUNIT_ASSERT_EQUAL(1, s.search(v, 3));

}

void Test::test3()
{
    Solution s;
    std::vector<int> v = {3, 1};

    CPPUNIT_ASSERT_EQUAL(0, s.search(v, 3));

}


int main()
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();
    return 0;
}
