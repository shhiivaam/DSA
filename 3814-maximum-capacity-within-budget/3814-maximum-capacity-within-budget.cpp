class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({costs[i], capacity[i]});
        }
        sort(v.begin(), v.end());
        vector<int> pref(n);
        pref[0] = v[0].second;
        for (int i = 1; i < n; i++) {
            pref[i] = max(pref[i - 1], v[i].second);
        }
        int ans = 0;
        for (int j = 0; j < n; j++) {
            if (v[j].first < budget) {
                ans = max(ans, v[j].second);
            }
            int remaining = budget - v[j].first - 1;
            int l = 0, r = j - 1, idx = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (v[mid].first <= remaining) {
                    idx = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (idx != -1) {
                ans = max(ans, v[j].second + pref[idx]);
            }
        }
        return ans;
    }
};
