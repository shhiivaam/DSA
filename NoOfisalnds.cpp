#include <iostream>
#include <vector>
using namespace std;
bool is_safe(int x, int y, int n, vector<vector<int>>& mtx) {
    return (x >= 0 && x < n && y >= 0 && y < n && mtx[x][y] == 1);
}
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
void dfs(vector<vector<int>>& vis, vector<vector<int>>& mtx, int i, int j, int n) {
    if(vis[i][j] == 1 || mtx[i][j] == 0) {
        return;
    }
    vis[i][j] = 1;
    for(int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if(is_safe(x, y, n, mtx) && vis[x][y] == 0) {
            dfs(vis, mtx, x, y, n);
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> mtx(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mtx[i][j];
        }
    }
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int no_of_lands = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!vis[i][j] && mtx[i][j] == 1) {
                dfs(vis, mtx, i, j, n);
                no_of_lands++;
            }
        }
    }
    cout << no_of_lands << endl;
}
