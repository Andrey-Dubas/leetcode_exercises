// https://leetcode.com/problems/merge-two-sorted-lists/description/
//
// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
// 
// Example:
// 
// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4


#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        
        std::vector<int>::iterator modifyIterator = nums.begin();
        for (std::vector<int>::iterator it = std::next(nums.begin()); it != nums.end(); ++it)
        {
            if (*it != *modifyIterator)
            {
                ++modifyIterator;
                *modifyIterator = *it;
            }
        }
        
        nums.erase(std::next(modifyIterator), nums.end());
        
        return nums.size();
    }
};

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

std::ostream& operator<< (std::ostream& os, const std::vector<int>& v)
{
    return os;
}

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
    std::vector<int> v1 = {1, 1, 2, 2};
    std::vector<int> v2 = {1, 2};
    CPPUNIT_ASSERT_EQUAL(int(v2.size()), s.removeDuplicates(v1));
    CPPUNIT_ASSERT_EQUAL(v2, v1);
}

void Test::test2()
{
    Solution s;
    std::vector<int> v1 = {};
    std::vector<int> v2 = {};
    CPPUNIT_ASSERT_EQUAL(int(v2.size()), s.removeDuplicates(v1));
    CPPUNIT_ASSERT_EQUAL(v2, v1);
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
