#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        const int NEG = -1e9;
        vector<vector<int>> prev(m, vector<int>(k + 1, NEG)), curr(m, vector<int>(k + 1, NEG));
        prev[0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int addScore = (grid[i][j] == 1 ? 1 : (grid[i][j] == 2 ? 2 : 0));
                int addCost  = (grid[i][j] == 0 ? 0 : 1);
                for (int cost = addCost; cost <= k; cost++) {
                    int best = NEG;
                    if (i > 0 && prev[j][cost - addCost] != NEG)
                        best = max(best, prev[j][cost - addCost]);
                    if (j > 0 && curr[j - 1][cost - addCost] != NEG)
                        best = max(best, curr[j - 1][cost - addCost]);
                    if (i == 0 && j == 0 && cost == addCost)
                        best = 0;
                    if (best != NEG)
                        curr[j][cost] = max(curr[j][cost], best + addScore);
                }
            }
            prev = curr;
            for (auto &x : curr) fill(x.begin(), x.end(), NEG);
        }

        int ans = -1;
        for (int c = 0; c <= k; c++)
            ans = max(ans, prev[m - 1][c]);
        return ans < 0 ? -1 : ans;
    }
};
