# leetcode no.94 Binary Tree Inorder Traversal

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# Follow up: 재귀쓰지말고 반복문으로만
class Solution:
    def inorderTraversal(self, root: TreeNode):
        node_stack, ret = [], []
        while True:
            while root:
                node_stack.append(root)
                root = root.left

            if not node_stack:
                return ret

            node = node_stack.pop()
            ret.append(node.val)
            root = node.right

        return ret
