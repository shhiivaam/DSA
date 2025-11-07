#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int64 k) {
        int n = stations.size();
        vector<int64> pref(n+1, 0);
        for (int i = 0; i < n; ++i) pref[i+1] = pref[i] + stations[i];
        vector<int64> power(n, 0);
        for (int i = 0; i < n; ++i) {
            int L = max(0, i - r);
            int R = min(n - 1, i + r);
            power[i] = pref[R+1] - pref[L];
        }

        auto ok = [&](int64 target) -> bool {
            vector<int64> diff(n+1, 0);
            int64 curAdd = 0;
            int64 rem = k;
            for (int i = 0; i < n; ++i) {
                curAdd += diff[i];
                int64 curPower = power[i] + curAdd;
                if (curPower < target) {
                    int64 need = target - curPower;
                    if (need > rem) return false;
                    rem -= need;
                    curAdd += need;
                    int end = i + 2*r + 1;
                    if (end < n) diff[end] -= need;
                }
            }
            return true;
        };

        int64 low = 0, high = (int64)2e18, ans = 0;
        while (low <= high) {
            int64 mid = low + (high - low) / 2;
            if (ok(mid)) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return ans;
    }
};
