class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val    = val 
        self.left   = left
        self.right  = right

class Solution:
    '''
    [Medium Problem]

        Given the "root" of a binary tree, return the number of nodes
        where the value of the node is equal to the average of the values
        in its subtree.

        Note:

        -   The average of "n" elements is the "sum" of the "n" elements divided by "n",
            and rounded down to the nearest integer.

        -   A subtree of root is a tree consisting of "root" and all of its descendants. 
    
    
    '''

    def averageOfSubtree(self, root: TreeNode) -> int:
        result = 0
        def dfs(node: TreeNode) -> tuple[int, int]:
            nonlocal result
            if node is None:
                return 0, 0
            left_sum,  left_count = dfs(node.left)
            right_sum, right_count = dfs(node.right)
            sub_tree_sum, sub_tree_count = left_sum + right_sum + node.val, left_count + right_count + 1
            if node.val == sub_tree_sum // sub_tree_count:
                result += 1
            return sub_tree_sum, sub_tree_count
        dfs(root)
        return result


if __name__ == "__main__":
    root = TreeNode(
        val = 4, 
        left = TreeNode(
            val     = 8, 
            left    = TreeNode(val=0), 
            right   = TreeNode(val=1)), 
        right = TreeNode(
            val     = 5,
            right   = TreeNode(val=6))
    )    

    print(f"Want : {5}, Was : {Solution().averageOfSubtree(root)}")

    print(f"Want : {1}, Was : {Solution().averageOfSubtree(TreeNode(val=1))}")