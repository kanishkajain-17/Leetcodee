/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {

    // TC = O(H)
    // SC = O(H) because finalLastChild() is recursive

    public TreeNode finalLastChild(TreeNode root) {
        if (root.right == null)
            return root;

        return finalLastChild(root.right);
    }

    public TreeNode helper(TreeNode root) {

        // Only right child exists or both children are null
        if (root.left == null)
            return root.right;

        // Only left child exists
        else if (root.right == null)
            return root.left;

        // Both children exist
        TreeNode rightChild = root.right;

        TreeNode lastRightOfLeft = finalLastChild(root.left);

        lastRightOfLeft.right = rightChild;

        return root.left;
    }

    public TreeNode deleteNode(TreeNode root, int key) {

        if (root == null)
            return null;

        if (root.val == key)
            return helper(root);

        TreeNode temp = root;

        while (root != null) {

            if (root.val > key) {

                if (root.left != null && root.left.val == key) {
                    root.left = helper(root.left);
                    break;
                } else {
                    root = root.left;
                }

            } else {

                if (root.right != null && root.right.val == key) {
                    root.right = helper(root.right);
                    break;
                } else {
                    root = root.right;
                }
            }
        }

        return temp;
    }
}