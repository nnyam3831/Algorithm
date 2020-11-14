# Leetcode no.98 Validate Binary Search Tree

# inorder search for bst => ascending list
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def inorder(self, node: TreeNode, node_list):
        if not node:
            return

        self.inorder(node.left, node_list)
        node_list.append(node.val)
        self.inorder(node.right, node_list)

    def isListSorted(self, _list):
        if sorted(_list) == _list:
            return True
        return False

    def isDuplicated(self, _list):
        listToSet = set(_list)
        return len(listToSet) == len(_list)

    def isValidBST(self, root: TreeNode) -> bool:

        node_list = []
        self.inorder(root, node_list)

        return not self.isDuplicated(node_list) and self.isListSorted(node_list)
