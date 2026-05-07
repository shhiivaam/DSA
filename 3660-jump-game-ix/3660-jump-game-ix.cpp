class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> sufMin(n);
        sufMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            sufMin[i] = min(sufMin[i + 1], nums[i]);
        }

        vector<int> ans(n);

        int start = 0;
        int mx = nums[0];

        for (int i = 0; i < n - 1; ++i) {
            mx = max(mx, nums[i]);
            if (mx <= sufMin[i + 1]) {
                for (int j = start; j <= i; ++j) {
                    ans[j] = mx;
                }

                start = i + 1;
                if (start < n) mx = nums[start];
            }
        }

        mx = nums[start];
        for (int i = start; i < n; ++i) {
            mx = max(mx, nums[i]);
        }

        for (int i = start; i < n; ++i) {
            ans[i] = mx;
        }

        return ans;
    }
};