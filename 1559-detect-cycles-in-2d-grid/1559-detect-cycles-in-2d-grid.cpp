class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    if (dfs(grid, visited, i, j, -1, -1, dx, dy)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r,
             int c, int pr, int pc, int dx[], int dy[]) {
        visited[r][c] = true;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() &&
                grid[nr][nc] == grid[r][c]) {
                if (visited[nr][nc]) {
                    if (nr != pr || nc != pc) {
                        return true;
                    }
                } else {
                    if (dfs(grid, visited, nr, nc, r, c, dx, dy)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};