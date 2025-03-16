// Category: algorithms
// Level: Easy
// Percent: 50.03299%



// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// 
// Given a string s, return true if it is a palindrome, or false otherwise.
// 
//  
// Example 1:
// 
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// 
// 
// Example 2:
// 
// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// 
// 
// Example 3:
// 
// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.
// 
// 
//  
// Constraints:
// 
// 
// 	1 <= s.length <= 2 * 10⁵
// 	s consists only of printable ASCII characters.
// 
 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j) {
            while (!isalnum(s[i]) && i <= j) {
                i++;
            }
            while (!isalnum(s[j]) && i <= j) {
                j--;
            }
            // Need to check the i <= j condition here in case it was broken in the earlier loops to 
            // skip over alphanumeric characters
            if (tolower(s[i]) != tolower(s[j]) && i <= j) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
