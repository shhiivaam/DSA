class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int resRows = m - k + 1;
        int resCols = n - k + 1;
        vector<vector<int>> ans(resRows, vector<int>(resCols, 0));
        for (int i = 0; i < resRows; ++i) {
            for (int j = 0; j < resCols; ++j) {
                set<int> distinctValues;
                for (int r = i; r < i + k; ++r) {
                    for (int c = j; c < j + k; ++c) {
                        distinctValues.insert(grid[r][c]);
                    }
                }
                if (distinctValues.size() < 2) {
                    ans[i][j] = 0;
                    continue;
                }
                int minDiff = INT_MAX;
                auto it = distinctValues.begin();
                int prev = *it;
                it++;
                while (it != distinctValues.end()) {
                    minDiff = min(minDiff, *it - prev);
                    prev = *it;
                    it++;
                }
                ans[i][j] = minDiff;
            }
        }
        return ans;
    }
};