/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    boolean check(TreeNode root , TreeNode target){
        if(root == null)
            return false;
        if(root == target)
            return true;
        
        return (check(root.left , target) || check(root.right , target));
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null || root == p || root == q)
            return root;

        boolean pInLeft = check(root.left , p);
        boolean qInLeft = check(root.left , q);

        if((pInLeft && !qInLeft) || (!pInLeft && qInLeft))
            return root;
            
        if(pInLeft && qInLeft)
            return lowestCommonAncestor(root.left , p , q);
        else
            return lowestCommonAncestor(root.right , p , q);      
        
    }
}