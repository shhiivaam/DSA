class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
         int n = nums.size();
        vector<int> ans(n);
        
        for (int i = 0; i < n; ++i) {
            int target = nums[i];
            int res = -1;
            if (target == 2) {
                ans[i] = -1;
                continue;
            }
            for (int x = 1; x < target; ++x) {
                if ((x | (x + 1)) == target) {
                    res = x;
                    break;
                }
            }
            ans[i] = res;
        }
        return ans;
    }
};