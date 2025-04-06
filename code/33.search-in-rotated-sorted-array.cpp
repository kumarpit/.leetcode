// Category: algorithms
// Level: Medium
// Percent: 42.25783%

// There is an integer array nums sorted in ascending order (with distinct
// values).
//
// Prior to being passed to your function, nums is possibly rotated at an
// unknown pivot index k (1 <= k < nums.length) such that the resulting array is
// [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
// (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3
// and become [4,5,6,7,0,1,2].
//
// Given the array nums after the possible rotation and an integer target,
// return the index of target if it is in nums, or -1 if it is not in nums.
//
// You must write an algorithm with O(log n) runtime complexity.
//
//  
// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// Example 3:
// Input: nums = [1], target = 0
// Output: -1
//
//  
// Constraints:
//
// 	1 <= nums.length <= 5000
// 	-10⁴ <= nums[i] <= 10⁴
// 	All values of nums are unique.
// 	nums is an ascending array that is possibly rotated.
// 	-10⁴ <= target <= 10⁴
//
//

// [4,5,6,7,0,1,2]
//  ^     ^     ^  // base case = no rotation when nums[l] < nums[r] because all
//  values are unique
// [0, 1, 2]
//  ^  ^  ^
// [0] // found it!

#include <vector>
using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    return _search(nums, 0, nums.size() - 1, target);
  }

private:
  // [5, 1, 3] 5
  int _search(vector<int> &nums, int l, int r, int target) {
    if (l > r)
      return -1;

    int m = (l + r) / 2;
    if (nums[m] == target) {
      return m;
    }

    // check for the case where there is no rotation
    if (nums[l] <= nums[r]) {
      // array is sorted and i can just do a regular binary search
      if (target < nums[m]) {
        return _search(nums, l, m - 1, target);
      } else {
        return _search(nums, m + 1, r, target);
      }

    } else { // there is a rotation

      // m is behind the pivot
      if (nums[l] <= nums[m]) {
        if (target >= nums[l] && target < nums[m]) {
          return _search(nums, l, m - 1, target);
        } else {
          return _search(nums, m + 1, r, target);
        }

        // m is the pivot
        // m is beyond the pivot
      } else {
        if (target < nums[m] || target > nums[r]) {
          return _search(nums, l, m - 1, target);
        } else {
          return _search(nums, m + 1, r, target);
        }
      }
    }
  }
};
