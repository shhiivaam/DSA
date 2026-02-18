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
    Map<Integer,Integer> mp = new HashMap<>();
    int postIdx ;
    private TreeNode buildBinaryTree(int[] inorder, int[] postorder , int inorderStart , int inorderEnd){
        if(postIdx < 0 || inorderStart > inorderEnd)
            return null;

        int ele = postorder[postIdx--];
        int idx = mp.get(ele);
        TreeNode root = new TreeNode(ele);
        root.right = buildBinaryTree(inorder , postorder  ,idx+1 , inorderEnd);
        root.left = buildBinaryTree(inorder , postorder  ,inorderStart , idx-1);
        return root;
    }
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int n = inorder.length;
        postIdx = n-1;
        int inorderStart = 0 , inorderEnd = n-1;
        for(int i = 0 ; i< n ; i++)
            mp.put(inorder[i] , i);

        return buildBinaryTree(inorder , postorder  , inorderStart , inorderEnd);
    }
}