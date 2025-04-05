// Category: algorithms
// Level: Hard
// Percent: 44.584675%

// Given two strings s and t of lengths m and n respectively, return the minimum
// window substring of s such that every character in t (including duplicates)
// is included in the window. If there is no such substring, return the empty
// string "".
//
// The testcases will be generated such that the answer is unique.
//
//  
// Example 1:
//
// ADOBEC
//
// DOBECODEBA
//
// ODEBANC
//
// ANC
// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C'
// from string t.
//
//
// Example 2:
//
// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
//
//
// Example 3:
//
// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
//
//
//  
// Constraints:
//
//
// 	m == s.length
// 	n == t.length
// 	1 <= m, n <= 10⁵
// 	s and t consist of uppercase and lowercase English letters.
//
//
//  
// Follow up: Could you find an algorithm that runs in O(m + n) time?
// TODO : ^

#include <climits>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    if (t.length() > s.length())
      return "";

    int l, r, _l, _r;
    l = r = _l = _r = 0;
    int min_len = INT_MAX;

    unordered_map<char, int> t_chars;
    for (char c : t) {
      t_chars[c]++;
    }

    unordered_map<char, int> substr_chars;
    while (r < s.length()) {
      substr_chars[s[r]]++;
      while (does_contain_chars(substr_chars, t_chars)) {
        if (length(l, r) < min_len) {
          _l = l;
          _r = r;
          min_len = length(l, r);
        }
        substr_chars[s[l]]--;
        l++;
      }
      r++;
    }

    if (min_len < INT_MAX)
      return s.substr(_l, min_len);
    return "";
  }

private:
  inline int length(int l, int r) { return r - l + 1; }

  // Returns true if b is "contained" in a
  bool does_contain_chars(unordered_map<char, int> &a,
                          unordered_map<char, int> &b) {
    for (auto kv : b) {
      if (a.count(kv.first) <= 0)
        return false;
      if (a[kv.first] < kv.second)
        return false;
    }
    return true;
  }
};
