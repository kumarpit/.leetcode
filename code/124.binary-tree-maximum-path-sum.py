# Category: algorithms
# Level: Hard
# Percent: 41.022373%



# A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
# 
# The path sum of a path is the sum of the node's values in the path.
# 
# Given the root of a binary tree, return the maximum path sum of any non-empty path.
# 
#  
# Example 1:
# 
# Input: root = [1,2,3]
# Output: 6
# Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
# 
# 
# Example 2:
# 
# Input: root = [-10,9,20,null,null,15,7]
# Output: 42
# Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
# 
# 
#  
# Constraints:
# 
# 
# 	The number of nodes in the tree is in the range [1, 3 * 10⁴].
# 	-1000 <= Node.val <= 1000
# 
 
from typing import List
from typing import Optional

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


result = float('-inf')

class Solution(object):
    def maxPathSum(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        # Assuming I want my split to be at the root
        self.__calculateMaxPathSum(root)

        global result
        max = result
        result = float('-inf')

        return max 

    def __calculateMaxPathSum(self, root):
        # Need to calculate the max sum _assuming_ split is at root 
        # And then assuming that we cannot split 
        
        if root is None: return 0 
        
        leftMaxSumWithoutSplit = self.__calculateMaxPathSum(root.left)
        rightMaxSumWithoutSplit = self.__calculateMaxPathSum(root.right)
        
        currentMaxWithoutSplit = max(root.val, max(root.val + leftMaxSumWithoutSplit, root.val + rightMaxSumWithoutSplit))
        
        global result
        result = max(result, max(root.val + leftMaxSumWithoutSplit + rightMaxSumWithoutSplit, currentMaxWithoutSplit))

        return currentMaxWithoutSplit


# def test():
#     tree1 = TreeNode(1, TreeNode(2), TreeNode(3))
#     solution = Solution()
#     print(solution.maxPathSum(tree1))
#
#     tree2 = TreeNode(-10, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
#     print(solution.maxPathSum(tree2))
#
# test()
