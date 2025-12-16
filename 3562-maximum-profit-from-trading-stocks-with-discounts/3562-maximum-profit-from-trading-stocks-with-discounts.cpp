#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
    int N;
    int B;
    vector<int> P;
    vector<int> F;
    vector<vector<int>> adj;
    const int INF = 1e9;

    vector<int> merge(const vector<int>& a, const vector<int>& b) {
        vector<int> res(B + 1, -INF);
        for (int i = 0; i <= B; ++i) {
            if (a[i] == -INF) continue;
            for (int j = 0; j <= B - i; ++j) {
                if (b[j] == -INF) continue;
                res[i + j] = max(res[i + j], a[i] + b[j]);
            }
        }
        return res;
    }

    pair<vector<int>, vector<int>> dfs(int u) {
        vector<int> current_no_buy(B + 1, -INF);
        vector<int> current_buy(B + 1, -INF);
        current_no_buy[0] = 0;
        current_buy[0] = 0;

        for (int v : adj[u]) {
            pair<vector<int>, vector<int>> child_res = dfs(v);
            current_no_buy = merge(current_no_buy, child_res.first);
            current_buy = merge(current_buy, child_res.second);
        }

        vector<int> res_parent_no(B + 1, -INF);
        vector<int> res_parent_yes(B + 1, -INF);

        for(int i = 0; i <= B; ++i) res_parent_no[i] = current_no_buy[i];
        int cost = P[u];
        int profit = F[u] - cost;
        for (int i = 0; i <= B - cost; ++i) {
            if (current_buy[i] != -INF) {
                res_parent_no[i + cost] = max(res_parent_no[i + cost], current_buy[i] + profit);
            }
        }

        for(int i = 0; i <= B; ++i) res_parent_yes[i] = current_no_buy[i];
        int cost_d = P[u] / 2;
        int profit_d = F[u] - cost_d;
        for (int i = 0; i <= B - cost_d; ++i) {
            if (current_buy[i] != -INF) {
                res_parent_yes[i + cost_d] = max(res_parent_yes[i + cost_d], current_buy[i] + profit_d);
            }
        }

        return {res_parent_no, res_parent_yes};
    }

public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        N = n;
        B = budget;
        P = present;
        F = future;
        adj.assign(n, vector<int>());
        for (auto& edge : hierarchy) {
            adj[edge[0] - 1].push_back(edge[1] - 1);
        }

        auto res = dfs(0);
        
        int ans = 0;
        for (int x : res.first) ans = max(ans, x);
        return ans;
    }
};