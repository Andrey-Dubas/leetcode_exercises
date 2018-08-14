// https://leetcode.com/problems/swap-nodes-in-pairs/description/
//
// Given a linked list, swap every two adjacent nodes and return its head.
// 
// Example:
// 
// Given 1->2->3->4, you should return the list as 2->1->4->3.
// 
// Note:
// 
//    Your algorithm should use only constant extra space.
//    You may not modify the values in the list's nodes, only nodes itself may be changed.


#include <vector>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* reverse(ListNode* head) {

    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current)
    {
        next = current->next;

        current->next = prev;
        
        prev = current;
        current = next;
    }

    return prev; 
}


#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <algorithm>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v)
{
    os << "[";
    if (!v.empty())
    {
        os << v[0];

        for (uint i = 1; i < v.size(); ++i)
        {
            os << ", " << v[i];
        }
    }
    os << "]";
    return os;
}

ListNode* formList(std::vector<int>& v)
{
	ListNode* node = new ListNode(0);
	ListNode* first = node;

	for (int val: v)
	{
		node->next = new ListNode(val);
		node = node->next;
	}

	return first->next;
}

std::vector<int> formVector(ListNode* node)
{
	std::vector<int> result;
	while (node)
	{
		result.push_back(node->val);
		node = node->next;
	}

	return result;
}

std::vector<int> apply(std::vector<int> input)
{
	return formVector(reverse(formList(input)));
} 


class Test: public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( Test ); 

    CPPUNIT_TEST( test1 );
    CPPUNIT_TEST( test2 );
    CPPUNIT_TEST( test3 );
    CPPUNIT_TEST( test4 );

    CPPUNIT_TEST_SUITE_END();

public:
    void test1();
    void test2();
    void test3();
    void test4();
};


CPPUNIT_TEST_SUITE_REGISTRATION( Test );

void Test::test1()
{
    std::vector<int> input  = {1, 2, 3, 4};
    std::vector<int> output = input;

    std::reverse(output.begin(), output.end());

    CPPUNIT_ASSERT_EQUAL(output, apply(input));
}

void Test::test2()
{
    std::vector<int> input  = {1, 2, 3, 4, 5};
    std::vector<int> output = input;

    std::reverse(output.begin(), output.end());

    CPPUNIT_ASSERT_EQUAL(output, apply(input));
}

void Test::test3()
{
    std::vector<int> input  = {1};
    std::vector<int> output = {1};

    CPPUNIT_ASSERT_EQUAL(output, apply(input));
}

void Test::test4()
{
    std::vector<int> input  = {};
    std::vector<int> output = {};

    CPPUNIT_ASSERT_EQUAL(output, apply(input));
}

int main()
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();
    return 0;
}
