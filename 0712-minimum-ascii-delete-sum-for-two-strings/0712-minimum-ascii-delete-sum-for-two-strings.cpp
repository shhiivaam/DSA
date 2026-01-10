class Solution {
public:
    vector<vector<int>> dp;

    int solve(string &s1, string &s2, int i, int j) {
        if (i < 0 && j < 0) return 0;

        if (i < 0) {
            int sum = 0;
            for (int k = 0; k <= j; k++) sum += s2[k];
            return sum;
        }

        if (j < 0) {
            int sum = 0;
            for (int k = 0; k <= i; k++) sum += s1[k];
            return sum;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i - 1, j - 1);
        }

        int deleteS1 = s1[i] + solve(s1, s2, i - 1, j);
        int deleteS2 = s2[j] + solve(s1, s2, i, j - 1);

        return dp[i][j] = min(deleteS1, deleteS2);
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        dp.assign(n, vector<int>(m, -1));
        return solve(s1, s2, n - 1, m - 1);
    }
};
