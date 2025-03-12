// Category: algorithms
// Level: Easy
// Percent: 66.08283%



// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// 
//  
// Example 1:
// 
// 
// Input: s = "anagram", t = "nagaram"
// 
// Output: true
// 
// 
// Example 2:
// 
// 
// Input: s = "rat", t = "car"
// 
// Output: false
// 
// 
//  
// Constraints:
// 
// 
// 	1 <= s.length, t.length <= 5 * 10⁴
// 	s and t consist of lowercase English letters.
// 
// 
//  
// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> char_counts;
        for (char c : s) {
            char_counts[c]++;
        }
        for (char c : t) {
            if (char_counts.count(c) == 0 || char_counts[c] == 0) {
                return false;
            }
            char_counts[c]--;
        } 
        return true;
    }
};

