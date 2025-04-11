// Category: algorithms
// Level: Hard
// Percent: 56.15505%

// You are given an array of k linked-lists lists, each linked-list is sorted in
// ascending order.
//
// Merge all the linked-lists into one sorted linked-list and return it.
//
//  
// Example 1:
//
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
//
//
// Example 2:
//
// Input: lists = []
// Output: []
//
//
// Example 3:
//
// Input: lists = [[]]
// Output: []
//
//
//  
// Constraints:
//
//
// 	k == lists.length
// 	0 <= k <= 10⁴
// 	0 <= lists[i].length <= 500
// 	-10⁴ <= lists[i][j] <= 10⁴
// 	lists[i] is sorted in ascending order.
// 	The sum of lists[i].length will not exceed 10⁴.
//

#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  // O(n * logk)
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0) {
      return nullptr;
    }

    vector<ListNode *> _lists = lists;
    vector<ListNode *> mergedLists;

    while (_lists.size() > 1) {
      mergedLists = {};

      for (int i = 0; i < _lists.size(); i += 2) {
        ListNode *list1 = _lists[i];
        ListNode *list2 = (i + 1) < _lists.size() ? _lists[i + 1] : nullptr;
        mergedLists.push_back(mergeLists(list1, list2));
      }

      _lists = mergedLists;
    }

    return _lists[0];
  }

private:
  ListNode *mergeLists(ListNode *l1, ListNode *l2) {
    if (!l1) {
      return l2;
    }
    if (!l2) {
      return l1;
    }

    ListNode sentinel(0);
    ListNode *curr = &sentinel;
    while (l1 && l2) {
      if (l1->val <= l2->val) {
        curr->next = l1;
        l1 = l1->next;
      } else {
        curr->next = l2;
        l2 = l2->next;
      }
      curr = curr->next;
    }
    if (l1) {
      curr->next = l1;
    } else if (l2) {
      curr->next = l2;
    }

    return sentinel.next;
  }
};
