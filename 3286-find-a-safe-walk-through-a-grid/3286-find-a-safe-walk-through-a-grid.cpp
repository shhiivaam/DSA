// class Solution {
// public:
//     bool _solve(int i, int j, vector<vector<int>>& grid, int h,
//                 int n, int m, vector<vector<int>>& vis) {
//         if (h <= 0) return false;
//         if (i == n - 1 && j == m - 1)  return true;

//         vis[i][j] = 1;
//         int dx[4] = {0, -1, 1, 0};
//         int dy[4] = {1, 0, 0, -1};
//         for (int k = 0; k < 4; k++) {
//             int nx = i + dx[k];
//             int ny = j + dy[k];

//             if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
//                 vis[nx][ny] == 0) {
//                 if (_solve(nx, ny, grid, h - grid[nx][ny],n, m, vis))
//                     return true;
//             }
//         }
//         vis[i][j] = 0;
//         return false;
//     }
//     bool findSafeWalk(vector<vector<int>>& grid, int health) {
//         int n = grid.size();
//         int m = grid[0].size();
//         health -= grid[0][0];
//         if (health <= 0) return false;
//         vector<vector<int>> vis(n, vector<int>(m, 0));
//         return _solve(0, 0, grid, health, n, m, vis);
//     }
// };
class Solution {
public:
    bool solve(int i, int j, vector<vector<int>>& grid, int h,
               int n, int m, vector<vector<int>>& best) {

        if (h <= 0)return false;
        if (i == n - 1 && j == m - 1)return true;
        if (best[i][j] >= h)  return false;

        best[i][j] = h;

        int dx[4] = {0, -1, 1, 0};
        int dy[4] = {1, 0, 0, -1};

        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (solve(nx, ny, grid, h - grid[nx][ny], n, m, best))
                    return true;
            }
        }
        return false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        health -= grid[0][0];
        if (health <= 0) return false;
        vector<vector<int>> best(n, vector<int>(m, -1));
        return solve(0, 0, grid, health, n, m, best);
    }
};