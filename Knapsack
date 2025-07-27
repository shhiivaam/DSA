#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll rec(ll idx, ll curWeight, vector<ll>& weights, vector<ll>& values, ll maxWeight, vector<vector<ll>>& dp) {
    if (idx == weights.size()) return 0;

    if (dp[idx][curWeight] != -1) return dp[idx][curWeight];

    ll notTake = rec(idx + 1, curWeight, weights, values, maxWeight, dp);

    ll take = 0;
    if (curWeight + weights[idx] <= maxWeight) {
        take = values[idx] + rec(idx + 1, curWeight + weights[idx], weights, values, maxWeight, dp);
    }
    return dp[idx][curWeight] = max(take, notTake);
}
int main() {
    ll n, maxWeight;
    cin >> n >> maxWeight;
    vector<ll> weights(n), values(n);
    for (ll i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(maxWeight + 1, -1));
    cout << rec(0, 0, weights, values, maxWeight, dp) << endl;
    return 0;
}
