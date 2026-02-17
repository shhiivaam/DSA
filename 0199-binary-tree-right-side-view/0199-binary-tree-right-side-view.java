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
    int getLevel(TreeNode root) {
        if (root == null)
            return 0;
        return 1 + Math.max(getLevel(root.left), getLevel(root.right));
    }

    void dfs(TreeNode root, List<Integer> arr, int curr) {
        if (root == null)
            return;
        if (arr.get(curr) == -1)
            arr.set(curr, root.val);
        dfs(root.right, arr, curr + 1);
        dfs(root.left, arr, curr + 1);
    }

    public List<Integer> rightSideView(TreeNode root) {
        int n = getLevel(root);
        List<Integer> list = new ArrayList<>(Collections.nCopies(n, -1));
        dfs(root, list, 0);
        return list;
    }
}