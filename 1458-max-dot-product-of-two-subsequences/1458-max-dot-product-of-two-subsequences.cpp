class Solution {
public:
    int _solve(vector<int>& a, vector<int>& b, int n, int m,
               vector<vector<int>>& dp) {
        if (n < 0 || m < 0)
            return INT_MIN / 2;
        if (dp[n][m] != -1)
            return dp[n][m];

        int take = a[n] * b[m];
        take = max(take, a[n] * b[m] + _solve(a, b, n - 1, m - 1, dp));

        int skipA = _solve(a, b, n - 1, m, dp);
        int skipB = _solve(a, b, n, m - 1, dp);

        return dp[n][m] = max({take, skipA, skipB});
    }
    int maxDotProduct(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN / 2));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {

            int take = a[i] * b[j];
            take = max(take, a[i] * b[j] + dp[i + 1][j + 1]);

            int skipA = dp[i + 1][j];
            int skipB = dp[i][j + 1];

            dp[i][j] = max({take, skipA, skipB});
        }
    }
    return dp[0][0];
    }
};