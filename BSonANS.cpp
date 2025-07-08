class Solution {
public:
    bool check(vector<vector<int>>& e, int k, int mid) {
        // Sort by value descending
        vector<vector<int>> events = e;
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        });

        set<int> occupied;
        int count = 0;
        int total = 0;

        for (auto& event : events) {
            int s = event[0];
            int t = event[1];
            bool conflict = false;
            // Check if any day in this range is already taken
            for (int d = s; d <= t; d++) {
                if (occupied.count(d)) {
                    conflict = true;
                    break;
                }
            }
            if (!conflict) {
                // Mark days as occupied
                for (int d = s; d <= t; d++) {
                    occupied.insert(d);
                }
                total += event[2];
                count++;
                if (count == k) break;
            }
        }
        return total >= mid;
    }

    int maxValue(vector<vector<int>>& e, int k) {
        int ans = 0;
        int lo = 0;
        int hi = 1e9;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(e, k, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
