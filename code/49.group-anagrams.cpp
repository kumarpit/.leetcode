// Category: algorithms
// Level: Medium
// Percent: 70.25731%



// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// 
//  
// Example 1:
// 
// 
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// 
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// 
// Explanation:
// 
// 
// 	There is no string in strs that can be rearranged to form "bat".
// 	The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
// 	The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
// 
// 
// 
// Example 2:
// 
// 
// Input: strs = [""]
// 
// Output: [[""]]
// 
// 
// Example 3:
// 
// 
// Input: strs = ["a"]
// 
// Output: [["a"]]
// 
// 
//  
// Constraints:
// 
// 
// 	1 <= strs.length <= 10⁴
// 	0 <= strs[i].length <= 100
// 	strs[i] consists of lowercase English letters.
// 
 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (string str : strs) {
            string original_str = str;
            sort(str.begin(), str.end());
            if (anagrams.count(str) > 0) {
                anagrams[str].push_back(original_str);
            } else {
                anagrams[str] = {original_str};
            }
        }
        vector<vector<string>> solution;
        for (auto pair : anagrams) {
            solution.push_back(pair.second);
        }
        return solution;
    }
};
