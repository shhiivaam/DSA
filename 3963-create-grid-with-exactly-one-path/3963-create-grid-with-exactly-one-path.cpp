class Solution {
public:
    vector<string> createGrid(int m, int n) {
       vector<string> ans(m, string(n, '#'));

        // Horizontal path: first row
        for (int j = 0; j < n; j++) {
            ans[0][j] = '.';
        }

        // Vertical path: last column
        for (int i = 1; i < m; i++) {
            ans[i][n - 1] = '.';
        }

        return ans;
    }
};