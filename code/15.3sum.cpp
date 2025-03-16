// Category: algorithms
// Level: Medium
// Percent: 36.33409%



// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// 
// Notice that the solution set must not contain duplicate triplets.
// 
//  
// Example 1:
// 
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// 
// 
// Example 2:
// 
// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// 
// 
// Example 3:
// 
// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.
// 
// 
//  
// Constraints:
// 
// 
// 	3 <= nums.length <= 3000
// 	-10⁵ <= nums[i] <= 10⁵
// 
//
/**
 * Input: nums = [-1,0,1,2,-1,-4]
 * sorted: [-4, -1, -1, 0, 1, 2]
 *
 * [ [-1, -1, 2], [-1, 1, 0] ]
 *
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size() - 1; i++) {
            // Skip over duplicate elements
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Now its essentially n iterations of twosum
            int l = i + 1;
            int r = nums.size() - 1;
            int to_find = -nums[i];
            while (l < r) {
                if (nums[l] + nums[r] == to_find) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    // Find the next unique element on either end
                    l++;
                    while (nums[l] == nums[l - 1] && l < r) {
                        l++;
                    }
                } else if (nums[l] + nums[r] < to_find) {
                    l++;
                } else { // nums[l] + nums[r] > to_find
                    r--;
                }
            }
        }

        return result;
    }
};
