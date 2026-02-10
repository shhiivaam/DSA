class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> e, o;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) {
                    e.insert(nums[j]);
                } else {
                    o.insert(nums[j]);
                }
                if (e.size() == o.size()) {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};