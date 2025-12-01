class Solution {
public:
    bool canRun(long long T, int n, vector<int>& b) {
        long long total = 0;
        for (long long x : b) {
            total += min(x, T);
        }
        return total >= T * n;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 0, high = 0;
        for (int x : batteries) high += x; 
        high /= n;
        long long ans = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (canRun(mid, n, batteries)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
