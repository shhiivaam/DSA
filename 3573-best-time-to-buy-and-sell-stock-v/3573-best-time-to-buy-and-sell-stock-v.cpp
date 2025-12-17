class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n == 0) return 0;
        
        long long INF = 1e18;
        vector<vector<long long>> dp(k + 1, vector<long long>(3, -INF));
        dp[0][0] = 0;

        for (int price : prices) {
            vector<vector<long long>> next_dp = dp;
            for (int i = 1; i <= k; ++i) {
                if (dp[i-1][0] != -INF) {
                    next_dp[i][1] = max(next_dp[i][1], dp[i-1][0] - price);
                    next_dp[i][2] = max(next_dp[i][2], dp[i-1][0] + price);
                }
                if (dp[i][1] != -INF) {
                    next_dp[i][0] = max(next_dp[i][0], dp[i][1] + price);
                }
                if (dp[i][2] != -INF) {
                    next_dp[i][0] = max(next_dp[i][0], dp[i][2] - price);
                }
            }
            dp = next_dp;
        }

        long long ans = 0;
        for (int i = 0; i <= k; ++i) {
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};