// https://leetcode.com/problems/search-insert-position/
// 
// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You may assume no duplicates in the array.


#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;

        int len = nums.size();
        int low = 0, high = len-1;

        while (high > low+1)
        {
            int middle = (high+low)/2;

            if (nums[middle] < target) {low = middle+1;}
            else if (nums[middle] > target) {high = middle-1;}
            else {return middle;}
        }

        if (target > nums[high]) {return high+1;}
        else if (target <= nums[low]) {return low;}
        else {return high;}
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
    CPPUNIT_TEST( test5 );
    CPPUNIT_TEST( test6 );

    CPPUNIT_TEST_SUITE_END();

public:
    void test1();
    void test2();
    void test3();
    void test4();
    void test5();
    void test6();
};

CPPUNIT_TEST_SUITE_REGISTRATION( Test );

void Test::test1()
{
    Solution s;
    std::vector<int> v = {1, 3, 5, 6};

    CPPUNIT_ASSERT_EQUAL(2, s.search(v, 5));
}

void Test::test2()
{
    Solution s;
    std::vector<int> v = {1,3};

    CPPUNIT_ASSERT_EQUAL(2, s.search(v, 5));

}

void Test::test3()
{
    Solution s;
    std::vector<int> v = {3, 1};

    CPPUNIT_ASSERT_EQUAL(0, s.search(v, 0));

}

void Test::test4()
{
    Solution s;
    std::vector<int> v = {1, 3, 5, 6};
    CPPUNIT_ASSERT_EQUAL(4, s.search(v, 7));
}

void Test::test5()
{
    Solution s;
    std::vector<int> v = {3, 1};
}

void Test::test6()
{
    Solution s;
    std::vector<int> v = {5, 1, 3};
}

int main()
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();
    return 0;
}
