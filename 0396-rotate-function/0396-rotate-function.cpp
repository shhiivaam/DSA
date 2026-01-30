class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long n = nums.size();
        long long sum = 0, f0 = 0;

        for (long long i = 0; i < n; i++) {
            sum += nums[i];
            f0 += i * nums[i];
        }

        long long ans = f0;
        long long cur = f0;

        for (long long k = 1; k < n; k++) {
            cur = cur + sum - n * nums[n - k];
            ans = max(ans, cur);
        }

        return (int)ans;
    }
};
