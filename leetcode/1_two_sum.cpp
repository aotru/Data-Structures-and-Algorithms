#include "leetcode.h"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> hash_map;
        
        for (int i = 0; i < n; ++i) {
            int difference = target - nums[i];
            auto it = hash_map.find(difference);
            
            if (it != end(hash_map)) {
                return {it->second, i};
            }
            
            else {
                hash_map[nums[i]] = i;
            }
        }
        
        return {}; // for compiler error
    }
};