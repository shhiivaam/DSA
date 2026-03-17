class Solution {
public:

long long dp[100001];

long long solve(int idx, vector<int>& costs){

    if(idx == 0) return 0;

    if(dp[idx] != -1) return dp[idx];

    long long ans = LLONG_MAX;

    if(idx >= 1){
        ans = min(ans, solve(idx-1, costs) + costs[idx-1] + 1);
    }

    if(idx >= 2){
        ans = min(ans, solve(idx-2, costs) + costs[idx-1] + 4);
    }

    if(idx >= 3){
        ans = min(ans, solve(idx-3, costs) + costs[idx-1] + 9);
    }

    return dp[idx] = ans;
}

int climbStairs(int n, vector<int>& costs) {

    memset(dp, -1, sizeof(dp));

    return solve(n, costs);
}

};