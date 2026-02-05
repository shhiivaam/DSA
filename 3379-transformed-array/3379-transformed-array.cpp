class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int ele = nums[i];

            if (ele > 0) {
                int idx = (i + ele) % n;
                ans.push_back(nums[idx]);
            }
            else if (ele < 0) {
                int idx = (i + ele) % n;
                if (idx < 0) idx += n;
                ans.push_back(nums[idx]);
            }
            else {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
