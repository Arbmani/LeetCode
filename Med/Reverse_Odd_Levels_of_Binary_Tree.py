from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    '''
    [Medium Problem]

        Given the "root" of a perfect binary tree, reverse the node values at each odd level of the tree. 

        -   For example, suppose the node value at level 3 are [2, 1, 3, 4, 7, 11, 29, 18],
            then is should become [18, 29, 11, 7, 4, 3, 1, 2]

        Return the root of the revered tree.

        A binary tree is perfect if all parent nodes have two children and all leaves are on the same level. 

        The level of a node is the number of edges along the path between it and the root node.


    '''


    def reverseOddLevels(self, root: TreeNode | None) -> TreeNode | None:
        queue = deque([root])
        level = 0

        while queue:
            if level % 2:
                left  = 0
                right = len(queue) - 1
                while left < right:
                    queue[left].val, queue[right].val = queue[right].val, queue[left].val
                    left  += 1
                    right -= 1
            for _ in range(len(queue)):
                curr = queue.popleft()
                if curr.left:
                    queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)
            level += 1

        return root



if __name__ == "__main__":

    root = TreeNode(val=2, left=(TreeNode(val=3, left=(TreeNode(val=8)), right=(TreeNode(val=13)))), right=(TreeNode(val=5, left=(TreeNode(val=21)), right=(TreeNode(val=34)))))
    ans_root = TreeNode(val=2, right=(TreeNode(val=3, left=(TreeNode(val=8)), right=(TreeNode(val=13)))), left=(TreeNode(val=5, left=(TreeNode(val=21)), right=(TreeNode(val=34)))))
    print(f"Want : {ans_root}, Was :  {Solution().reverseOddLevels(root)}")