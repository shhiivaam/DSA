class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long ans = 0;
        sort(nums.rbegin(), nums.rend());
        //    int n = nums.size() - k;
        for (int i = 0; i < k ; i++) {
            if (mul > 1) {
                long long h = 1ll * nums[i] * mul;
                ans = ans + h;
                mul -= 1;
            } else {
                ans += nums[i];
            }
        }
    return ans;
    }
};