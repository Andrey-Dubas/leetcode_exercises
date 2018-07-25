#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef unsigned int uint;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* toBeRemoved = head;
        ListNode* i = head;
        
        
        while (n > 0)
        {
            i = i->next;
            --n;
        }
        
        if (i == nullptr)
        {
            return head->next;
        }
        
        while (i->next)
        {
            i = i->next;
            toBeRemoved = toBeRemoved->next;
        }
        
        toBeRemoved->next = toBeRemoved->next->next;
        
        return head;
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

        for (int i = 1; i < v.size(); ++i)
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

std::vector<int> apply(std::vector<int> input, int n)
{
	Solution s;
	return formVector(s.removeNthFromEnd(formList(input), n));
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
    std::vector<int> input = {1,2,3,4,5};
    std::vector<int> output = {1,2,3,5};

    CPPUNIT_ASSERT_EQUAL(output, apply(input, 2));
}

void Test::test2()
{

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
