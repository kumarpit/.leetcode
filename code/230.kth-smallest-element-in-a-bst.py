# Category: algorithms
# Level: Medium
# Percent: 74.9345%



# Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
# 
#  
# Example 1:
# 
# Input: root = [3,1,4,null,2], k = 1
# Output: 1
# 
# 
# Example 2:
# 
# Input: root = [5,3,6,2,4,null,null,1], k = 3
# Output: 3
# 
# 
#  
# Constraints:
# 
# 
# 	The number of nodes in the tree is n.
# 	1 <= k <= n <= 10⁴
# 	0 <= Node.val <= 10⁴
# 
# 
#  
# Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
 

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: Optional[TreeNode]
        :type k: int
        :rtype: int
        """
        # iterative
        # n = 0
        # stack = []
        # curr = root
        #
        # while curr or stack:
        #     while curr:
        #         stack.append(curr)
        #         curr = curr.left
        #     curr = stack.pop()
        #     n += 1
        #     if n == k:
        #         return curr.val
        #     curr = curr.right
        
        self.count = 0
        self.k = k
        self.result = None
        self.__inorder_traversal(root)
        return self.result

    def __inorder_traversal(self, node):
        if not node or self.count >= self.k:
            return

        self.__inorder_traversal(node.left)

        # visit node
        self.count += 1
        if self.count == self.k:
            self.result = node.val
            return

        self.__inorder_traversal(node.right)

