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
    long long totalSum = 0;
    long long ans = 0;

    long long _generateSum(TreeNode* root, vector<long long>& allSums) {
        if (root == NULL) return 0;
        long long cur_sum = root->val;
        cur_sum += _generateSum(root->left, allSums);
        cur_sum += _generateSum(root->right, allSums);
        allSums.push_back(cur_sum);
        return cur_sum;
    }
    int maxProduct(TreeNode* root) {
        int mod = 1e9 + 7;
        vector<long long> allSums;
        totalSum = _generateSum(root, allSums);
        for (long long s : allSums) {
            ans = max(ans, s * (totalSum - s));
        }
        return ans % mod;
    }
};
