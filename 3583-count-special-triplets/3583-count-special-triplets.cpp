class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        int mod = 1e9 + 7;
        int max_val = 0;
        for (int num : nums) {
            if (num > max_val) max_val = num;
        }
        vector<int> left_freq(max_val + 1, 0);
        vector<int> right_freq(max_val + 1, 0);
        for (int num : nums) {
            right_freq[num]++;
        }
        for (int j = 0; j < n; ++j) {
            right_freq[nums[j]]--;
            int val_j = nums[j];
            if (val_j * 2 <= max_val) {
                long long left_count = left_freq[val_j * 2];
                long long right_count = right_freq[val_j * 2];
                count = (count + left_count * right_count) % mod;
            }
            left_freq[nums[j]]++;
        }
        return count;
    }
};