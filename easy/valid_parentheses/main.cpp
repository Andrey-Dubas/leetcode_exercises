// https://leetcode.com/problems/valid-parentheses/description/

// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// 
// An input string is valid if:
// 
//  Open brackets must be closed by the same type of brackets.
//  Open brackets must be closed in the correct order.



#include <stack>
#include <string>

using namespace std;

typedef unsigned int uint;

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '{')
            {
                stack.push('}');
            }
            if (s[i] == '[')
            {
                stack.push(']');
            }
            if (s[i] == '(')
            {
                stack.push(')');
            }
            
            if (s[i] == '}' || s[i] == ']' || s[i] == ')')
            {
                if (!stack.empty() && s[i] == stack.top())
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        
        return stack.empty();
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
    Solution s;

    CPPUNIT_ASSERT(s.isValid("()"));

}

void Test::test2()
{
    Solution s;

    CPPUNIT_ASSERT(s.isValid("()[]{}"));

}

void Test::test3()
{
	Solution s;

    CPPUNIT_ASSERT(!s.isValid("(]"));
}

void Test::test4()
{
	Solution s;

    CPPUNIT_ASSERT(s.isValid("({})"));
}

int main()
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();
    return 0;
}
