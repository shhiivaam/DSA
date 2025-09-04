class Solution {
public:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = INT_MAX;
        for (int idx = i; idx <= j; idx++) {
            int cost =  cuts[j + 1] - cuts[i - 1] +
                                     solve(i, idx - 1, cuts, dp) +
                                     solve(idx + 1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        vector<vector<int>> dp(c + 1,vector<int>(c + 1, -1));
        return solve(1, c, cuts, dp);
    }
};