class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = 1e9;
        vector<int> suffix(n);
        for(int i = n - 1; i >= 0; i--) {
            mini = min(mini, nums[i]);
            suffix[i] = mini;
        }

        int maxi = 0;
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            if(maxi - suffix[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};