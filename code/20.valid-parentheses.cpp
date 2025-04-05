// Category: algorithms
// Level: Easy
// Percent: 41.779934%

// Given a string s containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid.
//
// An input string is valid if:
//
//
// 	Open brackets must be closed by the same type of brackets.
// 	Open brackets must be closed in the correct order.
// 	Every close bracket has a corresponding open bracket of the same type.
//
//
//  
// Example 1:
//
//
// Input: s = "()"
//
// Output: true
//
//
// Example 2:
//
//
// Input: s = "()[]{}"
//
// Output: true
//
//
// Example 3:
//
//
// Input: s = "(]"
//
// Output: false
//
//
// Example 4:
//
//
// Input: s = "([])"
//
// Output: true
//
//
//  
// Constraints:
//
//
// 	1 <= s.length <= 10⁴
// 	s consists of parentheses only '()[]{}'.
//

#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    // Maps closing brackets to its opening pair
    unordered_map<char, char> bracket_map = {
        {']', '['}, {'}', '{'}, {')', '('}};

    stack<char> brackets;

    for (char c : s) {
      if (bracket_map.count(c) > 0) {
        // the current value atop the stack must be the corresponding opening
        // bracket
        if (brackets.empty() || brackets.top() != bracket_map[c])
          return false;
        brackets.pop();
        continue;
      }
      brackets.push(c);
    }

    return brackets.empty();
  }
};
