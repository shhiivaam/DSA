class Solution {
public:
    int solve(int n , vector<int>&dp){
        if(n == 0)  return 0 ;
        if(dp[n] != -1) return dp[n]; 
        int ans = INT_MAX;
        for(int i = 1 ; i*i <= n ; i++){
            int t = 1 + solve(n- i*i , dp);
            ans = min(ans , t);
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        vector<int>dp(n+1, -1);
        return solve(n , dp);
    }
};