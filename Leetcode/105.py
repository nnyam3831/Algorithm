# Leetcode no.105 Construct Binary Tree from Preorder and Inorder Traversal
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, preorder: [int], inorder: [int]) -> TreeNode:
        if preorder == [] or not preorder:
            return None
        pre_index, cur, node = 1, preorder[0], TreeNode(preorder[0])
        root = node
        parent = {}
        parent[node.val] = -1
        while pre_index < len(preorder):
            in_index = inorder.index(cur)
            print(node, node.val, parent[node.val])
            # check left
            if in_index > 0 and inorder[in_index-1] not in parent:
                parent[preorder[pre_index]] = node
                cur = preorder[pre_index]
                node.left = TreeNode(cur)
                node = node.left
                pre_index += 1
                continue
            # check right
            if in_index < len(inorder) - 1 and inorder[in_index + 1] not in parent:
                parent[preorder[pre_index]] = node
                cur = preorder[pre_index]
                node.right = TreeNode(cur)
                node = node.right
                pre_index += 1
                continue

            node = parent[node.val]
            cur = node.val

        return root


sol = Solution()
print(sol.buildTree([3, 9, 20, 15, 7], [9, 3, 15, 20, 7]))
