class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};
        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int time = curr[0], r = curr[1], c = curr[2];  
            if (r == n - 1 && c == n - 1) return time;     
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    pq.push({max(time, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
};
