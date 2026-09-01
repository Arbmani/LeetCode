from typing import Optional, List 

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val    = val 
        self.left   = left
        self.right  = right 
class Solution:
    '''
        Given the "root" of a binary tree, return all root-to-leaf paths in any order.

        A Leaf is a node with no children
    
    '''

    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        if not root:
            return root
        result  = []
        def Depth_First_Search(node, path):
            path += str(node.val)
            if not node.left and not node.right:
                result.append(path)
            if node.left:
                Depth_First_Search(node.left, path + "->")
            if node.right:
                Depth_First_Search(node.right, path + "->")
        Depth_First_Search(root, "")
        return result

