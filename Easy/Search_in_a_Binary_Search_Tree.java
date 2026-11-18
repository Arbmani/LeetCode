class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

/*

You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals 
val and return the subtree rooted with that node. If such a node does not exist, return null.

*/

class SolutionsearchBST {
    public TreeNode searchBST(TreeNode root, int val) {
        while (root != null){
            if (root.val == val) return root;
            if (val < root.val) root = root.left;
            else                root = root.right;
        }
        return null;
    }
}


