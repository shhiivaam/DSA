class Solution {
public:
    int minimumDistance(vector<int>& arr) {
        int n = arr.size(), minDis = INT_MAX;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);

        for (auto it : mp) {
            auto a = it.second;
            if (a.size() >= 3) {
                for (int x = 0; x <= a.size() - 3; x++) {
                    int i = a[x], j = a[x + 1], k = a[x + 2];
                    int diff = abs(i - j) + abs(j - k) + abs(k - i);
                    minDis = min(minDis, diff);
                }
            }
        }
        return minDis == INT_MAX ? -1 : minDis;
    }
};