// https://leetcode.com/problems/reverse-nodes-in-k-group/
//
// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
// 
// Example:
// 
// Given this linked list: 1->2->3->4->5
// 
// For k = 2, you should return: 2->1->4->3->5
// 
// For k = 3, you should return: 3->2->1->4->5
// 
// Note:
// 
//     Only constant extra memory is allowed.
//     You may not alter the values in the list's nodes, only nodes itself may be changed.



#include <vector>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:

    int moreThan(ListNode* node, int k)
    {
        while (node)
        {
            node = node->next;
            k--;
            if (k == 0) return true;
        }
        return false;
    }

    ListNode* reverseKGroup(ListNode* head, const int k) {

        ListNode* prev = nullptr, *current = head, *next = nullptr;

        ListNode* result = head;
        ListNode* prevGroupLeader = head;

        if (moreThan(current, k))
        {
            ListNode* first = current;

            for (int i = 0; i < k; ++i)
            {
                next = current->next;

                current->next = prev;

                prev = current;
                current = next;
            }
            result = prev;

            first->next = current;
        }

        while (moreThan(current, k))
        {
            ListNode* currentGroupLeader = current;

            ListNode* first = current;
            prev = current;
            current = prev->next;

            prev->next = nullptr;

            for (int i = 0; i < k-1; ++i)
            {
                next = current->next;

                current->next = prev;

                prev = current;
                current = next;
            }

            prevGroupLeader->next = prev;
            prevGroupLeader = currentGroupLeader;

            first->next = current;

        }




        return result;
    }
};


#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

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

std::vector<int> apply(std::vector<int> input, int k)
{
	Solution s;
	return formVector(s.reverseKGroup(formList(input), k));
} 


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
    std::vector<int> input  = {1, 2, 3, 4, 5};
    std::vector<int> output  = {2, 1, 4, 3, 5};

    CPPUNIT_ASSERT_EQUAL(output, apply(input, 2));
}

void Test::test2()
{
    std::vector<int> input  = {1, 2, 3, 4, 5};
    std::vector<int> output = {3, 2, 1, 4, 5};

    CPPUNIT_ASSERT_EQUAL(output, apply(input, 3));
}

void Test::test3()
{
    std::vector<int> input  = {1};
    std::vector<int> output = {1};

    CPPUNIT_ASSERT_EQUAL(output, apply(input, 2));
}

void Test::test4()
{
    std::vector<int> input  = {};
    std::vector<int> output = {};

    CPPUNIT_ASSERT_EQUAL(output, apply(input, 2));
}

void Test::test5()
{
    std::vector<int> input  = {1, 2, 3, 4};
    std::vector<int> output  = {2, 1, 4, 3};

    CPPUNIT_ASSERT_EQUAL(output, apply(input, 2));
}

void Test::test6()
{
    std::vector<int> input  = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> output  = {3, 2, 1, 6, 5, 4, 7};

    CPPUNIT_ASSERT_EQUAL(output, apply(input, 3));
}

int main()
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();
    return 0;
}
