/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>&arr , int l , int h){
        if (l > h)
            return nullptr;

        int m = (l+h)>>1;
        TreeNode* root = new TreeNode(arr[m]);
        root->left = solve(arr , l , m-1);
        root->right = solve(arr , m+1 , h);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums , 0 , nums.size()-1);
    }
};