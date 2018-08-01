#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_map>

#include <iostream>

using namespace std;

typedef unsigned int uint;

class Solution {
public:


    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        std::vector<int> AB; // = sort(A, B);
        std::unordered_map<int, int> CD;// = sort(C, D);
        
        for (uint i = 0; i < A.size(); ++i)
        {
            for (uint j = 0; j < A.size(); ++j)
            {
                AB.push_back(A[i] + B[j]);

                int sum = C[i] + D[j];
                auto found = CD.find(sum);
                if (found == CD.end())
                {
                    CD.insert(std::make_pair(sum, 1));
                }
                else
                {
                    ++found->second;
                }
            }
        }
        
        int result = 0;

        for (std::vector<int>::iterator it = AB.begin(); it != AB.end(); ++it)
        {
            auto found = CD.find(-(*it));
            if (found != CD.end())
            {
                result += found->second;
            }
        }

        return result;
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

    std::vector<int> A = {1, 2};
    std::vector<int> B = {-2, -1};
    std::vector<int> C = {-1, 2};
    std::vector<int> D = {0, 2};


    CPPUNIT_ASSERT_EQUAL(2, s.fourSumCount(A, B ,C, D));
}

void Test::test2()
{
    Solution s;

    std::vector<int> A = {0,-1,-1,-1,0,1,1};
    std::vector<int> B = {-1,-1,1,0,1,-1,0};
    std::vector<int> C = {0,1,0,-1,1,0,1};
    std::vector<int> D = {1,0,-1,-1,1,0,-1};

    CPPUNIT_ASSERT_EQUAL(570, s.fourSumCount(A, B ,C, D));
}

void Test::test3()
{
    std::vector<int> A = {0,0,0};
    std::vector<int> B = {0,0,0};
    std::vector<int> C = {0,0,0};
    std::vector<int> D = {0,0,0};

    Solution s;
    CPPUNIT_ASSERT_EQUAL(81, s.fourSumCount(A, B ,C, D));
}

int main()
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();
    return 0;
}
