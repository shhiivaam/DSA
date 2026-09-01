class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int ans = 0;
        vector<int> used(101, 0);

        for (int i = 0; i < nums.size(); i++) {

            if (used[nums[i]] == 1)
                continue;

            int freq = 0;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] == nums[i]) {
                    freq++;
                }
            }
            int count = 0;
            int j = i;

            while (j < nums.size() && nums[j] == nums[i]) {
                count++;
                j++;
            }

            used[nums[i]] = 1;

            if (count == freq) {
                ans++;
            }
        }

        return ans;
    }
};