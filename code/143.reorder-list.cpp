// Category: algorithms
// Level: Medium
// Percent: 61.460144%

// You are given the head of a singly linked-list. The list can be represented
// as:
//
// L₀ → L₁ → … → Ln - 1 → Ln
//
//
// Reorder the list to be on the following form:
//
// L₀ → Ln → L₁ → Ln - 1 → L₂ → Ln - 2 → …
//
//
// You may not modify the values in the list's nodes. Only nodes themselves may
// be changed.
//
//  
// Example 1:
//
// Input: head = [1,2,3,4]
// Output: [1,4,2,3]
//
//
// Example 2:
//
// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]
//
//
//  
// Constraints:
//
//
// 	The number of nodes in the list is in the range [1, 5 * 10⁴].
// 	1 <= Node.val <= 1000
//

#include <vector>
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
  void reorderList(ListNode *head) {
    // naive solution
    /*if (!head)*/
    /*  return;*/
    /**/
    /*vector<ListNode *> nodes;*/
    /*int n = 0;*/
    /**/
    /*while (head) {*/
    /*  nodes.push_back(head);*/
    /*  n++;*/
    /*  head = head->next;*/
    /*}*/
    /**/
    /*ListNode sentinel(0);*/
    /*ListNode *curr = &sentinel;*/
    /**/
    /*for (int i = 0; i < n; i++) {*/
    /*  int curr_idx;*/
    /*  if (i % 2 == 0) {*/
    /*    curr_idx = i / 2;*/
    /*  } else {*/
    /*    curr_idx = n - ((i - 1) / 2) - 1;*/
    /*  }*/
    /*  curr->next = nodes[curr_idx];*/
    /*  curr = curr->next;*/
    /*}*/
    /*curr->next = nullptr;*/

    //  first we find the mid-point of the list
    if (!head || !head->next)
      return;

    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // at this point, slow should be pointing to the middle node
    // or, in other words, the end of the first list.
    ListNode *first_half = head;
    ListNode *second_half = reverseList(slow->next, nullptr);
    slow->next = nullptr; // IMPORTANT to consolidate the fact that we now have
                          // two distinct lists

    ListNode *ret = head;
    bool take_from_end = false;

    while (first_half) {
      ListNode *temp;

      if (take_from_end) {
        temp = second_half;
        second_half = second_half->next;
      } else {
        temp = first_half;
        first_half = first_half->next;
      }

      ret->next = temp;
      take_from_end = !take_from_end;
      ret = ret->next;
    }
  }

private:
  ListNode *reverseList(ListNode *head, ListNode *prev) {
    if (!head)
      return prev;
    ListNode *next = head->next;
    head->next = prev;
    return reverseList(next, head);
  }
};
