// class Solution {
// public:
//     long long maxSubarraySum(vector<int>& nums, int k) {
//         // bool has_pos = false;
//         // for (int i = 0; i < nums.size(); i++) {
//         //     if (nums[i] >= 0) {
//         //         has_pos = true;
//         //     }
//         // }
//         // if (!has_pos && k > 0)
//         //     return -1;

//         // sort(nums.begin(), nums.end());
//         long long currSum = nums[0];
//         long long maxSum = nums[0];

//         for (int i = 1; i < nums.size(); i++) {
//             currSum = max(1LL * nums[i], currSum + nums[i]);
//             maxSum = max(maxSum, currSum);
//         }
//         if (maxSum < 0) {
//             double x = maxSum /= k;
//             return ceil(x);
//         }
//         return maxSum * 1ll * k;
//     }
// };
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        auto getMaxSubarray = [&](bool isMultiply) {
            long long dp0 = 0;
            long long dp1 = -1e16;
            long long dp2 = -1e16;
            long long maxSum = -1e16;
            
            for (int x : nums) {
                long long val = x;
                long long mod_val = isMultiply ? (val * k) : (val / k);
                
                long long nxt_dp0 = max(0LL, dp0) + val;
                long long nxt_dp1 = max({0LL, dp0, dp1}) + mod_val;
                long long nxt_dp2 = max(dp1, dp2) + val;
                
                dp0 = nxt_dp0;
                dp1 = nxt_dp1;
                dp2 = nxt_dp2;
                
                maxSum = max({maxSum, dp1, dp2});
            }
            return maxSum;
        };
        
        return max(getMaxSubarray(true), getMaxSubarray(false));
    }
};