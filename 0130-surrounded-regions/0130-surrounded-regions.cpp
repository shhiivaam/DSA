class Solution {
private:
    bool check(int x, int y, vector<vector<char>>& board, vector<vector<int>>& vis, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && board[x][y] == 'O');
    }
    void bfs(int sr, int sc, vector<vector<int>>& vis, vector<vector<char>>& board, int n, int m) {
        queue<pair<int, int>> q;
        vis[sr][sc] = 1;
        q.push({sr, sc});
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (check(nx, ny, board, vis, n, m)) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') bfs(i, 0, vis, board, n, m);
            if (board[i][m - 1] == 'O') bfs(i, m - 1, vis, board, n, m);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') bfs(0, j, vis, board, n, m);
            if (board[n - 1][j] == 'O') bfs(n - 1, j, vis, board, n, m);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j]) {
                    board[i][j] = 'O';  
                } else {
                    board[i][j] = 'X'; 
                }
            }
        }
    }
};