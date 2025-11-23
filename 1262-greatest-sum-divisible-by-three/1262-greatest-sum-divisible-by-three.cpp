class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int dp[3] = {0, -1000000000, -1000000000};
        for (int n : nums) {
            int a = dp[0], b = dp[1], c = dp[2];
            if (a != -1000000000) dp[(a + n) % 3] = max(dp[(a + n) % 3], a + n);
            if (b != -1000000000) dp[(b + n) % 3] = max(dp[(b + n) % 3], b + n);
            if (c != -1000000000) dp[(c + n) % 3] = max(dp[(c + n) % 3], c + n);
        }
        return dp[0];
    }
};