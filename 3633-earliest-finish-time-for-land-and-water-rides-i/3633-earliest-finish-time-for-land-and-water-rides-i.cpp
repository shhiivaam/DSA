class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans = INT_MAX;

        int t1 = INT_MAX;
        for (int i = 0; i < n; i++) {
            t1 = min(t1, landStartTime[i] + landDuration[i]);
        }

        for (int i = 0; i < m; i++) {
            int t2 = max(t1, waterStartTime[i]) + waterDuration[i];
            ans = min(ans, t2);
        }

        t1 = INT_MAX;
        for (int i = 0; i < m; i++) {
            t1 = min(t1, waterStartTime[i] + waterDuration[i]);
        }

        for (int i = 0; i < n; i++) {
            int t2 = max(t1, landStartTime[i]) + landDuration[i];
            ans = min(ans, t2);
        }

        return ans;
    }
};