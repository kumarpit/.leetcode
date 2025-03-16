// Category: algorithms
// Level: Medium
// Percent: 67.340935%



// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// 
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// 
// You must write an algorithm that runs in O(n) time and without using the division operation.
// 
//  
// Example 1:
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:
// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
// 
//  
// Constraints:
// 
// 
// 	2 <= nums.length <= 10⁵
// 	-30 <= nums[i] <= 30
// 	The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
// 
// 
//  
// Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
 

/**
 * Approach 1:
 * 1. First we calculate the _suffix_ product array 
 * [2, 3, 0, 9, 1]
 * ==> [0, 0, 9, 1, 1]
 * 
 * 2. Then we can calculate the _prefix_ product array 
 * ==> [1, 2, 6, 0, 0]
 *
 * Now, using these two arrays, we can determine the product of the array except self 
 *
 * res[i] = prefix_product[i] * suffix_product[i]
 * ==> [0, 0, 54, 0, 0]
 *
 * [2, 3, 9, 1]
 * pfx: [1, 2, 6, 54]
 * sfx: [27, 9, 1, 1]
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> results(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                results[i] = 1;
            } else {
                results[i] = results[i - 1] * nums[i - 1];
            }
        }

        int suffix_so_far = 1;
        for (int i = n - 1; i >= 0; i--) {
            results[i] *= suffix_so_far;
            suffix_so_far *= nums[i];
        }

        return results;
    }
};
