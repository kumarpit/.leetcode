// Category: algorithms
// Level: Easy
// Percent: 66.201485%

// You are given the heads of two sorted linked lists list1 and list2.
//
// Merge the two lists into one sorted list. The list should be made by splicing
// together the nodes of the first two lists.
//
// Return the head of the merged linked list.
//
//  
// Example 1:
//
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
//
//
// Example 2:
//
// Input: list1 = [], list2 = []
// Output: []
//
//
// Example 3:
//
// Input: list1 = [], list2 = [0]
// Output: [0]
//
//
//  
// Constraints:
//
//
// 	The number of nodes in both lists is in the range [0, 50].
// 	-100 <= Node.val <= 100
// 	Both list1 and list2 are sorted in non-decreasing order.
//

#include <cstdlib>
using namespace std;

// Definition for singly-linked list.
/*struct ListNode {*/
/*  int val;*/
/*  ListNode *next;*/
/*  ListNode() : val(0), next(nullptr) {}*/
/*  ListNode(int x) : val(x), next(nullptr) {}*/
/*  ListNode(int x, ListNode *next) : val(x), next(next) {}*/
/*};*/

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (!list1) {
      return list2;
    }
    if (!list2) {
      return list1;
    }
    // recursive solution
    /*if (list1->val <= list2->val) {*/
    /*  list1->next = mergeTwoLists(list1->next, list2);*/
    /*  return list1;*/
    /*} else {*/
    /*  list2->next = mergeTwoLists(list1, list2->next);*/
    /*  return list2;*/
    /*}*/

    // iterative solution
    ListNode sentinel(0); // doesn't need to be allocated on the heap since we
                          // only don't copy the original ListNodes, just this
                          // sentinel node to rearrange them
    ListNode *curr = &sentinel;
    while (list1 && list2) {
      if (list1->val <= list2->val) {
        curr->next = list1;
        list1 = list1->next;
      } else {
        curr->next = list2;
        list2 = list2->next;
      }
      curr = curr->next;
    }
    if (!list1) {
      curr->next = list2;
    } else if (!list2) {
      curr->next = list1;
    }

    return sentinel.next;
  }
};
