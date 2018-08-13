#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

typedef unsigned int uint;


std::ostream& operator<<(std::ostream& os, const std::vector<int>& v)
{
    os << '{';

    if (!v.empty())
    {
        os << v[0];

        for (uint i = 1; i < v.size(); ++i)
        {
            os << ", " << v[i];
        }
    }

    os << '}';

    return os;
}


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) {return ;}

        int decreasingIndex = -1;
        for (int i = nums.size()-2; i >= 0; --i)
        {
            if (nums[i] < nums[i+1])
            {
                decreasingIndex = i;
                break;
            }
        }

        if (decreasingIndex == -1)
        {
            std::sort(nums.begin(), nums.end());
            return;
        }

        int i;
        for (i = decreasingIndex+1; i < nums.size(); ++i)
        {
            if (nums[i] <= nums[decreasingIndex])
            {
                break;
            }
        }
        //if (i == nums.size()) {--i;}

        std::swap(nums[decreasingIndex], nums[i-1]);

        std::reverse(nums.begin() + decreasingIndex+1, nums.end());

    }
};

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>

class Test: public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( Test ); 

    CPPUNIT_TEST( empty_list_test);
    CPPUNIT_TEST( one_element_list_test);
    CPPUNIT_TEST( sorted_in_descendant_order_test);
    CPPUNIT_TEST( test1 );
    CPPUNIT_TEST( test2 );
    CPPUNIT_TEST( test3 );
    CPPUNIT_TEST( test4 );
    CPPUNIT_TEST( test5 );

    CPPUNIT_TEST_SUITE_END();

public:
    void empty_list_test();
    void one_element_list_test();
    void sorted_in_descendant_order_test();
    void test1();
    void test2();
    void test3();
    void test4();
    void test5();
};

CPPUNIT_TEST_SUITE_REGISTRATION( Test );



void Test::empty_list_test()
{
    Solution s;
    std::vector<int> v = {};
    s.nextPermutation(v);

    CPPUNIT_ASSERT(v.empty());
}

void Test::one_element_list_test()
{
    Solution s;
    std::vector<int> v = {0};
    s.nextPermutation(v);

    CPPUNIT_ASSERT(size_t(1));
    CPPUNIT_ASSERT_EQUAL(0, v[0]);
}

void Test::sorted_in_descendant_order_test()
{
    Solution s;
    std::vector<int> v      = {8, 5, 3, 1};
    std::vector<int> expect = {1, 3, 5, 8};
    s.nextPermutation(v);

    CPPUNIT_ASSERT_EQUAL(expect, v);
}

void Test::test1()
{
    Solution s;
    std::vector<int> v      = {1, 2, 3};
    std::vector<int> expect = {1, 3, 2};
    s.nextPermutation(v);

    CPPUNIT_ASSERT_EQUAL(expect, v);
}

void Test::test2()
{
    Solution s;
    std::vector<int> v      = {1, 1 ,5};
    std::vector<int> expect = {1, 5, 1};
    s.nextPermutation(v);

    CPPUNIT_ASSERT_EQUAL(expect, v);
}

void Test::test3()
{
    Solution s;
    std::vector<int> v      = {1, 5 ,1, 10};
    std::vector<int> expect = v;
    std::next_permutation(expect.begin(), expect.end());
    s.nextPermutation(v);

    CPPUNIT_ASSERT_EQUAL(expect, v);
}

void Test::test4()
{
    Solution s;
    std::vector<int> v      = {15, 5 ,1, 10};
    std::vector<int> expect = v;
    std::next_permutation(expect.begin(), expect.end());
    s.nextPermutation(v);

    CPPUNIT_ASSERT_EQUAL(expect, v);
}

void Test::test5()
{
    Solution s;
    std::vector<int> v      = {1, 3, 2};
    std::vector<int> expect = v;
    std::next_permutation(expect.begin(), expect.end());
    s.nextPermutation(v);

    CPPUNIT_ASSERT_EQUAL(expect, v);
}

int main()
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();
    return 0;
}
