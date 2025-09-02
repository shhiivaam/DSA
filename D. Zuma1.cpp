#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 1; i--) {
        for (int j = i; j <= n; j++) {

            if (i == j) { 
                dp[i][j] = 1;
                continue; 
            }

            dp[i][j] = 1 + dp[i + 1][j];

            if (i + 1 <= j && v[i] == v[i + 1]) {
                dp[i][j] = min(dp[i][j], 1 + dp[i + 2][j]);
            }

            for (int k = i + 2; k <= j; k++) {
                if (v[i] == v[k]) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
                }
            }
        }
    }
    cout << dp[1][n] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
