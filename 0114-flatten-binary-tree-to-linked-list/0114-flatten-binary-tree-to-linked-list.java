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
    public void flatten(TreeNode root) {
        if (root == null)
            return;
        Stack<TreeNode> stk = new Stack<>();
        stk.push(root);
        while (!stk.isEmpty()) {
            TreeNode curr = stk.peek();
            stk.pop();
            if (curr.right != null)
                stk.push(curr.right);
            if (curr.left != null)
                stk.push(curr.left);
            if (!stk.isEmpty())
                curr.right = stk.peek();
            curr.left = null;
        }
    }
}