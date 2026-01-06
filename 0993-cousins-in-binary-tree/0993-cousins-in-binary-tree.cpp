class Solution {
public:
    TreeNode* px = NULL;
    TreeNode* py = NULL;
    int _depth(TreeNode* root, TreeNode* parent, int x, TreeNode*& par) {
        if (root == NULL) return -1;

        if (root->val == x) {
            par = parent;
            return 0;
        }

        int left = _depth(root->left, root, x, par);
        if (left != -1) return left + 1;

        int right = _depth(root->right, root, x, par);
        if (right != -1) return right + 1;

        return -1;
    }

    bool isCousins(TreeNode* root, int x, int y) {
        int dx = _depth(root, NULL, x, px);
        int dy = _depth(root, NULL, y, py);

        return (dx == dy) && (px != py);
    }
};
