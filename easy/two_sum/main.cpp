// https://leetcode.com/problems/two-sum/description/

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); ++i)
        {
            int remain = target - nums[i];
            std::unordered_map<int, int>::const_iterator it = hash.find(remain);
            if (it != hash.end())
            {
                std::vector<int> result;
                result.push_back(hash[remain]);
                result.push_back(i);
                return result;
            }
            hash[nums[i]] = i;
        }
    }
};
