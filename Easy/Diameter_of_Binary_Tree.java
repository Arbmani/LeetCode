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

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

*/

class SolutionDiameter_of_Binary_Tree {
    private int diameter = 0;
    private int dfs(TreeNode node){
        if (node == null) return 0;
        int leftHeight  = dfs(node.left);
        int rightHeight = dfs(node.right);

        diameter = Math.max(diameter, leftHeight + rightHeight);
        return 1 + Math.max(leftHeight, rightHeight);
    }


    public int diameterOfBinaryTree(TreeNode root) {
        dfs(root);
        return diameter;
    }
}


public class Diameter_of_Binary_Tree {
    public static void main(String[] args) {

        
    }
}
