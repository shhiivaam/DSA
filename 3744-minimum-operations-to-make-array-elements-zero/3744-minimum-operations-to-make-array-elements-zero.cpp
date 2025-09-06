class Solution {
public:
     long long solveQuery(long long l, long long r) {
        long long totalSteps = 0;
        long long start = 1;
        int k = 1;  // step count for current interval

        while (start <= r) {
            long long end = start * 4 - 1; // end of interval for step k
            long long left = max(l, start);
            long long right = min(r, end);

            if (left <= right) {
                long long count = right - left + 1;
                totalSteps += count * 1LL * k;
            }

            start *= 4;
            k++;
        }
        return (totalSteps + 1) / 2;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto &q : queries) {
            ans += solveQuery(q[0], q[1]);
        }
        return ans;
    }
};