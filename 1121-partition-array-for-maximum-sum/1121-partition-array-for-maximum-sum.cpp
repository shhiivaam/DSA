class Solution {
private:
    int solve(int idx, int k, vector<int>& arr, vector<int>& dp) {
        int n = arr.size();
        if (idx >= n) return 0; 

        if (dp[idx] != -1) return dp[idx];

        int maxVal = 0, ans = 0;
        for (int i = idx; i < min(idx + k, n); i++) {
            maxVal = max(maxVal, arr[i]);
            int len = i - idx + 1;
            ans = max(ans, maxVal * len + solve(i + 1, k, arr, dp));
        }
        return dp[idx] = ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, k, arr, dp);
    }
};
