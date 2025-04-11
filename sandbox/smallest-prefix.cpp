/*You're given:*/
/**/
/*A string s containing only digits '0'–'9'.*/
/*An array of strings arr[], where each string is also made of digits.*/
/*For each query g in arr, you must:*/
/**/
/*Find the smallest prefix (starting from index 0) of s that contains all
 * characters (with frequency) in g.*/
/*If such a prefix doesn’t exist, return -1.*/
/*Constraints:*/
/**/
/*Characters must be accessed sequentially (can’t skip around s).*/
/*Queries are independent.*/

#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> countMinimumCharacters(const string &s,
                                   const vector<string> &queries) {
  int n = s.size();
  // freq[i][d] = number of digit d seen in prefix s[0..i]
  vector<array<int, 10>> freq(n);

  array<int, 10> count{};
  for (int i = 0; i < n; ++i) {
    count[s[i] - '0']++;
    freq[i] = count;
  }

  vector<int> result;
  for (const string &q : queries) {
    array<int, 10> need{};
    for (char c : q)
      need[c - '0']++;

    // Binary search on prefix length
    int left = 0, right = n - 1, answer = -1;
    while (left <= right) {
      int mid = (left + right) / 2;

      bool ok = true;
      for (int d = 0; d < 10; ++d) {
        if (freq[mid][d] < need[d]) {
          ok = false;
          break;
        }
      }

      if (ok) {
        answer = mid + 1; // +1 for length
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    result.push_back(answer);
  }

  return result;
}
