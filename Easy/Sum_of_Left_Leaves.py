from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    '''
    [Easy Problem]

        Given the root of a binary tree, return the sum of all left leaves.

        A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
    
    '''
    def sumOfLeftLeaves(self, root: TreeNode | None) -> int:
        if not root: return 0

        queue = deque([root])
        total = 0
        while queue:
            node = queue.popleft()
            if node.left:
                if not node.left.left and not node.left.right:
                    total += node.left.val
                else:
                    queue.append(node.left)
            if node.right:
                queue.append(node.right)
        return total


    def sumOfLeftLeaves_dfs(self, root: TreeNode | None) -> int:
        def dfs(node: TreeNode | None) -> int:
            if not node : return 0
            total = 0

            if node.left:
                if not node.left.left and not node.left.right:
                    total += node.left.val
                else:
                    total += dfs(node.left)
            total += dfs(node.right)
            return total
        return dfs(root) 

        