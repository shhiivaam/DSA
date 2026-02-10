class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        const long long NEG = -1e18;

        static long long dp[201][201][201];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int x = 0; x <= k; x++) {
                    dp[i][j][x] = NEG;
                }
            }
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j][0] = 0;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int x = 1; x <= k; x++) {
                    dp[i][j][x] = max(
                        dp[i - 1][j][x],
                        dp[i][j - 1][x]
                    );

                    dp[i][j][x] = max(
                        dp[i][j][x],
                        (long long)nums1[i - 1] * nums2[j - 1] + dp[i - 1][j - 1][x - 1]
                    );
                }
            }
        }

        return dp[n][m][k];
    }
};
