# Category: algorithms
# Level: Medium
# Percent: 66.36776%



# Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
# 
#  
# Example 1:
# 
# Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
# Output: [3,9,20,null,null,15,7]
# 
# 
# Example 2:
# 
# Input: preorder = [-1], inorder = [-1]
# Output: [-1]
# 
# 
#  
# Constraints:
# 
# 
# 	1 <= preorder.length <= 3000
# 	inorder.length == preorder.length
# 	-3000 <= preorder[i], inorder[i] <= 3000
# 	preorder and inorder consist of unique values.
# 	Each value of inorder also appears in preorder.
# 	preorder is guaranteed to be the preorder traversal of the tree.
# 	inorder is guaranteed to be the inorder traversal of the tree.
# 
 

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: Optional[TreeNode]
        """

        if not preorder or not inorder:
            return None

        root = preorder[0]
        root_index = inorder.index(root)
        root_node = TreeNode(root)
        root_node.left = self.buildTree(preorder[1:root_index + 1], inorder[:root_index])
        root_node.right = self.buildTree(preorder[root_index + 1:], inorder[root_index + 1:])
        
        return root_node


# Total time complexity for this algorithm is O(n^2) because there are a total of n recursive calls (one for each node)
# and for each recursive call, we perform O(n) operation in finding the index of the root element in the inorder array 
# Moreover, the slicing operations also take O(k) time 
# This can be optimized by using a hashmap for the inorder value array to achieve O(1) lookup and manually keeping track 
# of indices rather than slicing
