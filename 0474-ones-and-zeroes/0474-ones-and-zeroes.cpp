class Solution {
public:
    int solve(int idx, int m, int n, vector<pair<int, int>>& count,
              vector<vector<vector<int>>>& dp) {
        if (idx >= count.size())
            return 0;
        if (dp[idx][m][n] != -1)
            return dp[idx][m][n];

        int exc = solve(idx + 1, m, n, count, dp);
        int inc = 0;

        int zero = count[idx].first;
        int one = count[idx].second;

        if (zero <= m && one <= n)
            inc = 1 + solve(idx + 1, m - zero, n - one, count, dp);

        return dp[idx][m][n] = max(inc, exc);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> count;
        for (auto s : strs) {
            int ones = 0, zeros = 0;
            for (auto i : s)
                if (i == '0')
                    zeros++;
                else
                    ones++;
            count.push_back({zeros, ones});
        }
        vector<vector<vector<int>>> dp(
            strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(0, m, n, count, dp);
    }
};