#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int r, int c, vector<vector<int>>& h, vector<vector<int>>& vis) {
        vis[r][c] = 1;
        for (auto &d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            if (vis[nr][nc]) continue;
            if (h[nr][nc] < h[r][c]) continue;
            dfs(nr, nc, h, vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        m = h.size();
        n = h[0].size();
        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> atl(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            dfs(i, 0, h, pac);
            dfs(i, n-1, h, atl);
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j, h, pac);
            dfs(m-1, j, h, atl);
        }
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};
