// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// 
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// 
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
// 
// You are given a target value to search. If found in the array return its index, otherwise return -1.
// 
// You may assume no duplicate exists in the array.
// 
// Your algorithm's runtime complexity must be in the order of O(log n).
// 
// Example 1:
// 
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// 
// Example 2:
// 
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1


#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        const int len = nums.size();
        if (len == 0) { return -1;}
        
        int baseline = nums[0];
        
        int low = 0, high = len-1;
        
        while (true)
        {
            
            if (nums[high] <= nums[(high-1+len)%len]) { low = high; }
            if (nums[low]  <= nums[(low -1+len)%len]) { break; }
            
            int middle = (high+low)/2;
            if      (nums[middle] < baseline) {high = middle; }
            else if (nums[middle] > baseline) {low  = middle+1;}
        }
        int minIndex = low;

        low = minIndex; high = len-1+minIndex;
        
        while (high >= low)
        {
            int middle = (high+low)/2;
            int middleEl = nums[middle%len];
            
            if      (middleEl > target) {high = middle-1;}
            else if (middleEl < target) {low  = middle+1;}
            else {return middle%len;}
        }
        
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

void Test::test4()
{
    Solution s;
    std::vector<int> v = {1, 3, 5};
    CPPUNIT_ASSERT_EQUAL(-1, s.search(v, 0));
}

void Test::test5()
{
    Solution s;
    std::vector<int> v = {3, 1};
    CPPUNIT_ASSERT_EQUAL(1, s.search(v, 1));
}

void Test::test6()
{
    Solution s;
    std::vector<int> v = {5, 1, 3};
    CPPUNIT_ASSERT_EQUAL(0, s.search(v, 5));
}

int main()
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();
    return 0;
}
