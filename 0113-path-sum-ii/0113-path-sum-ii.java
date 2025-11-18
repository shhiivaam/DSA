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
    void dfs(TreeNode root, int targetSum, int sum, List<Integer> temp, List<List<Integer>> ans) {
        if (root == null)return;
        temp.add(root.val);
        sum += root.val;
        if (root.right == null && root.left == null && sum == targetSum)
            ans.add(new ArrayList<>(temp));
        dfs(root.left, targetSum, sum, temp, ans);
        dfs(root.right, targetSum, sum, temp, ans);
        temp.remove(temp.size() - 1);
    }

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> arr = new ArrayList<>();
        dfs(root, targetSum, 0, arr, ans);
        return ans;
    }
}