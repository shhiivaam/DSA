class Solution {
 public:
  long long getDescentPeriods(vector<int>& prices) {
    long ans = 1;  
    int dp = 1;
// Lwre ka leetcode and grind
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] == prices[i - 1] - 1)
        ++dp;
      else
        dp = 1;
      ans += dp;
    }

    return ans;
  }
};