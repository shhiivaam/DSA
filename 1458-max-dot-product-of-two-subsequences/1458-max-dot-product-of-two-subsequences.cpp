class Solution {
public:
int _solve(vector<int>& a, vector<int>& b, int n, int m,
vector<vector<int>>&dp) {
    if (n < 0 || m < 0) return INT_MIN / 2;
    if(dp[n][m] != -1) return dp[n][m];

    int take = a[n] * b[m];
    take = max(take, a[n] * b[m] + _solve(a, b, n-1, m-1,dp));

    int skipA = _solve(a, b, n-1, m,dp);
    int skipB = _solve(a, b, n, m-1,dp);

    return dp[n][m] = max({take, skipA, skipB});
}
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
       int n =nums1.size();
       int m = nums2.size(); 
       vector<vector<int>>dp(n,vector<int>(m,-1));
       int ans = _solve(nums1,nums2,n-1,m-1,dp); 
       return ans;
    }
};