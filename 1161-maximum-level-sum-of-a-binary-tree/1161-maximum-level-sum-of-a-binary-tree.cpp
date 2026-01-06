class Solution {
public:
    void _solve(TreeNode* root, int level, vector<long long>& levelSum) {
        if (root == NULL)
            return;
        if (level >= levelSum.size()) {
            levelSum.push_back(0);
        }
        levelSum[level] += root->val;
        _solve(root->left, level + 1, levelSum);
        _solve(root->right, level + 1, levelSum);
    }

    int maxLevelSum(TreeNode* root) {
        vector<long long> levelSum;
        _solve(root, 0, levelSum);
        
        auto it = max_element(levelSum.begin(), levelSum.end());
        int level = it - levelSum.begin() + 1;
       return level;
    }
};
