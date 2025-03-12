// Category: algorithms
// Level: Medium
// Percent: 64.01758%



// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
// 
//  
// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:
// Input: nums = [1], k = 1
// Output: [1]
// 
//  
// Constraints:
// 
// 
// 	1 <= nums.length <= 10⁵
// 	-10⁴ <= nums[i] <= 10⁴
// 	k is in the range [1, the number of unique elements in the array].
// 	It is guaranteed that the answer is unique.
// 
// 
//  
// Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
// Using bucket sort
//        unordered_map<int, int> num_counts;
//        for (int num : nums) {
//            num_counts[num]++;
//        }
//        vector<vector<int>> bucket(nums.size() + 1); 
//        for (const auto& [key, value] : num_counts) {
//           bucket[value].push_back(key); 
//        }
//        vector<int> top_k_freq;
//        for (int i = bucket.size() - 1; i >= 0; i--) {
//                for (int num : bucket[i]) {
//                    top_k_freq.push_back(num);
//                    if (top_k_freq.size() == k) {
//                        return top_k_freq;
//                    }
//                }
//        }
//
//        return top_k_freq;
//
// Using priority queue
        unordered_map<int, int> num_counts;
        for (int num : nums) {
            num_counts[num]++;
        }

        auto comparator = [](const pair<int, int>& l, const pair<int, int>& r) {
            return l.second > r.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> min_heap;

        for (const auto& [num, count] : num_counts) {
            min_heap.push({num, count});
            if (min_heap.size() > k) {
                min_heap.pop(); // In order to maintain top k frequent elements in the heap
            }
        }

        vector<int> res;
        while (!min_heap.empty()) {
            res.push_back(min_heap.top().first);
            min_heap.pop();
        }

        return res;
    }
};
