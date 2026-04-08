class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int mod = 1e9 + 7;

        for (auto &q : queries) {
            int l = q[0], r = q[1], step = q[2], val = q[3];
            if (val == 0) continue; 
            for (int i = l; i <= r; i += step) {
                nums[i] = (1LL * nums[i] * val) % mod;
            }
        }
        int ans = 0;
        for (int x : nums) ans ^= x;

        return ans;
    }
};