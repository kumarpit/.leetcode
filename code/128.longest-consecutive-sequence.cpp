// Category: algorithms
// Level: Medium
// Percent: 47.226418%



// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// 
// You must write an algorithm that runs in O(n) time.
// 
//  
// Example 1:
// 
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// 
// 
// Example 2:
// 
// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
// 
// 
// Example 3:
// 
// Input: nums = [1,0,1,2]
// Output: 3
// 
// 
//  
// Constraints:
// 
// 
// 	0 <= nums.length <= 10⁵
// 	-10⁹ <= nums[i] <= 10⁹
// 
 
/**
 * Approach:
 *
 * 1. Iterate over the list and insert all elements into a set (we don't care about duplicates)
 * 2. ^ gives us constanat time lookup for any element in the list - since we are interested in the longest consecutive sequence, 
 * we only count the length of sequences starting at elements for which there does not exist an i-1 element
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unordered because we want a hash-table backed implementation to achieve constant time lookup and insertion
        std::unordered_set<int> nums_table;
        for (int num : nums) {
            nums_table.insert(num);
        }
        int max_streak = 0;
        for (int num : nums) {
            if (nums_table.count(num - 1) == 0) {
                // Count longest sequence from this element
                int streak = 1;
                while (nums_table.count(num + 1) > 0) {
                    num++;
                    streak++;
                }
                max_streak = max(max_streak, streak);
            }
        }

        return max_streak;
    }
};
