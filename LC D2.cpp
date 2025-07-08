class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        // Sort by end time
        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        // Create an array of ends for binary search
        vector<int> ends;
        for (auto &e : events) ends.push_back(e[1]);

        // dp[i][j]: max value considering first i events and selecting at most j intervals
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; i++) {
            int s = events[i - 1][0];
            int e = events[i - 1][1];
            int v = events[i - 1][2];

            // Find the last event that ends before current event starts
            int l = lower_bound(ends.begin(), ends.end(), s) - ends.begin();

            for (int j = 1; j <= k; j++) {
                // Skip this event
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);

                // Take this event
                dp[i][j] = max(dp[i][j], dp[l][j - 1] + v);
            }
        }

        return dp[n][k];
    }
};
