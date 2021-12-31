#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

// Given an integer array nums, find number of distinct contiguous subarrays with at 
// most k odd elements. Two subarrays are distinct when they have at least one different element.



int k_odd(vector<int>& nums, int k) {
    unordered_set<string> subarrays;
    int n = nums.size();
    int total = 0;
    for (int i = 0; i < n; ++i) {
        int odd_count = 0;
        string subarray;
        for (int j = i; j < n; ++j) {
            odd_count += nums[j] % 2;
            subarray += (nums[j] - '0');

            if (odd_count <= k) {
                if (!subarrays.count(subarray)) {
                    ++total;
                    subarrays.insert(subarray);
                }
            }

            else {
                break;
            }
        }
    }
    return total;
}
int main() {
    vector<int> nums {3, 2, 3, 4};
    cout << k_odd(nums, 1) << endl;
}