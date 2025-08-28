#include <bits/stdc++.h>
using namespace std;
int n;
int dp[1005][3][4]; 
int rec(int cr, int cc,int last,vector<vector<int>>& games) {
    if (cr >= n || cc < 0 || cc >= 3) return -1e9;
    if (cr == n - 1) return games[cr][cc];
    if (dp[cr][cc][last + 1] != -1) return dp[cr][cc][last + 1];

    int ans = -1e9;

    for (int nc = 0; nc < 3; nc++) {
        if (nc != cc) {
            ans = max(ans, games[cr][cc] + rec(cr + 1, nc, cc, games));
        }
    }

    return dp[cr][cc][last + 1] = ans;
}

void solve() {
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = -1e9;
    for (int start_col = 0; start_col < 3; start_col++) {
        ans = max(ans, rec(0, start_col, -1, arr));
    }
    cout << ans << "\n";
}

int main() {
     ios::sync_with_stdio(false);
     cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}


