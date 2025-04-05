// Category: algorithms
// Level: Easy
// Percent: 54.71328%

// You are given an array prices where prices[i] is the price of a given stock
// on the ith day.
//
// You want to maximize your profit by choosing a single day to buy one stock
// and choosing a different day in the future to sell that stock.
//
// Return the maximum profit you can achieve from this transaction. If you
// cannot achieve any profit, return 0.
//
//  
// Example 1:
//
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit =
// 6-1 = 5. Note that buying on day 2 and selling on day 1 is not allowed
// because you must buy before you sell.
//
//
// Example 2:
//
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.
//
//
//  
// Constraints:
//
//
// 	1 <= prices.length <= 10⁵
// 	0 <= prices[i] <= 10⁴
//

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    if (n == 1)
      return 0;

    // A two-pointer approach
    int buy = 0;
    int sell = buy + 1;
    int max_profit_so_far = -1;
    while (sell < n) {
      int buy_price = prices[buy];
      int current_price = prices[sell];

      if (current_price < buy_price) {
        buy = sell;
        sell++;
        continue;
      }

      int current_profit = current_price - buy_price;
      max_profit_so_far = max(max_profit_so_far, current_profit);
      sell++;
    }

    return max(max_profit_so_far, 0);
  }
};
