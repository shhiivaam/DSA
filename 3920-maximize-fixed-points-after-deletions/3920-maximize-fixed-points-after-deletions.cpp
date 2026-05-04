class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        vector<pair<int, int>> candidates;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= i) {
                candidates.push_back({nums[i], i - nums[i]});
            }
        }

        sort(candidates.begin(), candidates.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });

        vector<int> tails;
        for (auto& p : candidates) {
            int val = p.second;
            auto it = upper_bound(tails.begin(), tails.end(), val);
            if (it == tails.end()) {
                tails.push_back(val);
            } else {
                *it = val;
            }
        }

        return tails.size();
    }
};