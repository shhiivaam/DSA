class Solution {
public:
    const int mod = 1e9 + 7;
    long long maxDp[16][16];
    long long minDp[16][16];
    bool vis[16][16];

 void solve(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0) return;
        if (vis[i][j]) return;
        if (i == 0 && j == 0) {
            maxDp[i][j] = minDp[i][j] = grid[0][0];
            vis[i][j] = true;
            return;
        }

        solve(i - 1, j, grid);
        solve(i, j - 1, grid);

        long long mx = LLONG_MIN;
        long long mn = LLONG_MAX;
        long long val = grid[i][j];
        if (i > 0) {
            mx = max(mx, maxDp[i-1][j] * val);
            mx = max(mx, minDp[i-1][j] * val);
            mn = min(mn, maxDp[i-1][j] * val);
            mn = min(mn, minDp[i-1][j] * val);
        }

        if (j > 0) {
            mx = max(mx, maxDp[i][j-1] * val);
            mx = max(mx, minDp[i][j-1] * val);
            mn = min(mn, maxDp[i][j-1] * val);
            mn = min(mn, minDp[i][j-1] * val);
        }
        maxDp[i][j] = mx;
        minDp[i][j] = mn;
        vis[i][j] = true;
    }
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(vis, false, sizeof(vis));
        solve(n - 1, m - 1, grid);
        long long ans = maxDp[n-1][m-1];
        if (ans < 0) return -1;
        return ans % mod;
    }
};