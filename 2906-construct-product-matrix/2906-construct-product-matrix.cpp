class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;

        vector<int> flat;
        for (auto &row : grid) {
            for (auto &val : row) {
                flat.push_back(val % mod);
            }
        }
        int size = flat.size();
        vector<int> prefix(size, 1), suffix(size, 1);

        for (int i = 1; i < size; i++) {
            prefix[i] = (prefix[i - 1] * flat[i - 1]) % mod;
        }

        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * flat[i + 1]) % mod;
        }

        vector<vector<int>> ans(n, vector<int>(m));
        int k = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = (prefix[k] * suffix[k]) % mod;
                k++;
            }
        }
        return ans;
    }
};