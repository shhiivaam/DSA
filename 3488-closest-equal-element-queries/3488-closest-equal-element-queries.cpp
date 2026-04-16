class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int idx : queries) {
            int val = nums[idx];
            vector<int>& v = mp[val];

            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int pos = lower_bound(v.begin(), v.end(), idx) - v.begin();

            int prev = (pos == 0 ? v.back() : v[pos - 1]);
            int next = (pos == v.size() - 1 ? v[0] : v[pos + 1]);

            int d1 = abs(idx - prev);
            int d2 = abs(idx - next);

            int dist1 = min(d1, n - d1);
            int dist2 = min(d2, n - d2);

            ans.push_back(min(dist1, dist2));
        }

        return ans;
    }
};