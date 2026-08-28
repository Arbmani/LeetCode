from typing import Optional

'''
    Binary Tree Maximum Path Sum

    
    A Path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence
    has an edge connecting them. A node can only appear in the sequence at most once. Note that
    the path does not need to pass through the root.

    The path sum of a oath is the sum of the node's values in the path.

    Given the root of a binary tree, return the maximum path sum of any non-empty path. 

'''




class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val 
        self.left = left 
        self.right = right 

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        result = float("-inf")
        def Depth_First_Search(node : Optional[TreeNode]):
            nonlocal result
            if not node:
                return 0

            l_Max = max(0, Depth_First_Search(node.left))
            r_Max = max(0, Depth_First_Search(node.right))

            result = max(result, node.val + l_Max + r_Max)
            return node.val + max(l_Max, r_Max)
        Depth_First_Search(root)
        return result



if __name__ == "__main__":
    sol = Solution()

    root = TreeNode(val=1, left=TreeNode(val=2), right=TreeNode(val=3))

    print(sol.maxPathSum(root))