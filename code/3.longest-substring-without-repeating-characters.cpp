// Category: algorithms
// Level: Medium
// Percent: 36.249367%

// Given a string s, find the length of the longest substring without duplicate
// characters.
//
//  
// Example 1:
//
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
//
//
// Example 2:
//
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
//
// Example 3:
//
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a
// substring.
//
//
//  
// Constraints:
//
//
// 	0 <= s.length <= 5 * 10⁴
// 	s consists of English letters, digits, symbols and spaces.
//

#include <string>
#include <unordered_map>
using namespace std;

// Sliding window approach with a map storing the positions if the characters
// in the current substring
//
// abcabcbb
// ^
// ^
// {a: 0}
//
// ^ ^
// {a: 0, b: 1}
//
// ^  ^
// {a: 0, b:1 , c:2}
//
// ^   ^
// record my current length (right - left)
// set left to the position map[char_at(right)] + 1
// map[char_at(right)] = right
//
// {a: 3: b: 1, c: 2}
// NOTE: each time i look up the map, check to see if the entry is valid
// for the current left pointer position

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.length() == 0)
      return 0;
    if (s.length() == 1)
      return 1;

    // at this point onwards s.length is atleast 2
    int left = 0;
    int right = 1;
    int max_length = 1;
    int curr_length = max_length;

    unordered_map<char, int> seen;
    seen.insert({s[left], left});

    // aabaab!bb (expected 3)
    while (right < s.length()) {
      // check if the current character at the 'right' position has already been
      // included in the current substring
      if (seen.count(s[right]) <= 0) {
        // this char is not seen before
        seen.insert({s[right], right});

      } else {

        if (seen[s[right]] < left) {
          seen[s[right]] = right;
        } else {
          // character has already been included in the current substring
          max_length = max(max_length, curr_length);
          left = seen[s[right]] + 1;
          seen[s[right]] = right;
          curr_length = right - left;
        }
      }

      right++;
      curr_length++;
    }

    return max(max_length, curr_length);
  }
};
