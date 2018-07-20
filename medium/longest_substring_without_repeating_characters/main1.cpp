// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
//
// Given a string, find the length of the longest substring without repeating characters.
//
// Examples:
// Given "abcabcbb", the answer is "abc", which the length is 3.
// Given "bbbbb", the answer is "b", with the length of 1.
// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include <vector>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(const std::string& s) {
        std::vector<bool> marked(256, false);
        int currentOffset = 0;
        int maxLen = 0;

        int i;
        for (i = 0; i < s.size(); ++i)
        {
            int ch = int(s[i]);
            if (marked[ch] == true)
            {
                maxLen = std::max(maxLen, i-currentOffset);
                while (s[currentOffset] != s[i])
                {
                    marked[int(s[currentOffset])] = false;
                    ++currentOffset;
                }
                ++currentOffset;
            }
            marked[int(s[i])] = true;
        }

        maxLen = std::max(maxLen, i-currentOffset);

        return maxLen;
    }
};


#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

class Test: public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( Test ); 

    CPPUNIT_TEST( test2 );
    CPPUNIT_TEST( test3 );

    CPPUNIT_TEST_SUITE_END();

public:
    void vector2NumTest();
    void test2();
    void test3();
};

CPPUNIT_TEST_SUITE_REGISTRATION( Test );


void Test::test2()
{
    std::string str1 = "abcabcbb";
    std::string str2 = "bbbbb";
    std::string str3 = "";
    std::string str4 = "pwwkew";
    std::string str5 = "aab";

    int l1 = 3;
    int l2 = 1;
    int l3 = 0;
    int l4 = 3;
    int l5 = 2;

    Solution s;
    CPPUNIT_ASSERT_EQUAL(l1, s.lengthOfLongestSubstring(str1));
    CPPUNIT_ASSERT_EQUAL(l2, s.lengthOfLongestSubstring(str2));
    CPPUNIT_ASSERT_EQUAL(l3, s.lengthOfLongestSubstring(str3));
    CPPUNIT_ASSERT_EQUAL(l4, s.lengthOfLongestSubstring(str4));
    CPPUNIT_ASSERT_EQUAL(l5, s.lengthOfLongestSubstring(str5));

    
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
