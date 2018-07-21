#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* vector2Node(const std::vector<int>& v)
{
    ListNode* current = nullptr;
    ListNode* next = nullptr;

    for (int i = v.size()-1; i >= 0; --i)
    {
        current = new ListNode(v[i]);
        current->next = next;
        next = current;  
    } 

    return next;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ten = 0;
        int sum = 0;
        ListNode* next = nullptr;
        ListNode* current = nullptr;
        
        while (l1 && l2)
        {
            sum = l1->val + l2->val + ten;
            ten = sum/10;
            sum = sum%10;
            
            current = new ListNode(sum);
            current->next = next;
            next = current;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if (l1 == nullptr)
        {
            l1 = l2;
        }
        
        while (l1)
        {
            sum = l1->val + ten;
            ten = sum/10;
            sum = sum%10;
            
            current = new ListNode(sum);
            current->next = next;
            next = current;
            
            l1 = l1->next;
        }
        
        if (ten)
        {
            current = new ListNode(ten);
            current->next = next;
        }
        
        // ListNode* first = current;
        ListNode* prev = nullptr;
        next = current->next;
        
        while (current)
        {
            next = current->next;
            current->next = prev;
            
            prev = current;
            current = next;
        }

        return prev;
        
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
    std::vector<int> v1 = {2, 4, 3};
    ListNode* node = vector2Node(v1);

    CPPUNIT_ASSERT(node);
    CPPUNIT_ASSERT_EQUAL(node->val, 2);

    node = node->next;
    CPPUNIT_ASSERT(node);
    CPPUNIT_ASSERT_EQUAL(node->val, 4);

    node = node->next;
    CPPUNIT_ASSERT(node);
    CPPUNIT_ASSERT_EQUAL(node->val, 3);
}

void Test::test2()
{
    std::vector<int> v1 = {2, 4, 3};
    std::vector<int> v2 = {5, 6, 4};

    Solution s;
    ListNode* node = s.addTwoNumbers(vector2Node(v1), vector2Node(v2));

    CPPUNIT_ASSERT(node);
    CPPUNIT_ASSERT_EQUAL(node->val, 7);

    node = node->next;
    CPPUNIT_ASSERT(node);
    CPPUNIT_ASSERT_EQUAL(node->val, 0);

    node = node->next;
    CPPUNIT_ASSERT(node);
    CPPUNIT_ASSERT_EQUAL(node->val, 8);
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
