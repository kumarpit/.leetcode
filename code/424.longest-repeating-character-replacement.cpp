// Category: algorithms
// Level: Medium
// Percent: 56.331573%

// You are given a string s and an integer k. You can choose any character of
// the string and change it to any other uppercase English character. You can
// perform this operation at most k times.
//
// Return the length of the longest substring containing the same letter you can
// get after performing the above operations.
//
//  
// Example 1:
//
// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.
//
//
// Example 2:
//
// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.
//
// k = 1 
// ABBBBBBBBB
// Constraints:
//
//
// 	1 <= s.length <= 10⁵
// 	s consists of only uppercase English letters.
// 	0 <= k <= s.length
//

// Sliding window approach
// Window valid condition:
// - If window len - count of most frequent character <= k, the window is valid

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    if (s.length() == 1)
      return 1;
    // this point onwards s.length is atleast 2
    int l = 0;
    int r = 0;

    unordered_map<char, int> char_count;
    int max_length = 1;
    int max_char_count = 0;

    while (r < s.length()) {
      char_count[s[r]]++;
      max_char_count = max(max_char_count, char_count[s[r]]);
      if ((r - l + 1 - max_char_count) > k) {
        char_count[s[l++]]--;
      } else {
        max_length = max(max_length, r - l + 1);
      }
      r++;
    }

    return max_length;
  }
};
