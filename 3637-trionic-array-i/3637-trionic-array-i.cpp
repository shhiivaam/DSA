class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        bool up = false, down = false, lup = false;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) return false;
            if (!down && !lup) {
                if (nums[i] > nums[i - 1]) {
                    up = true;
                } else if (nums[i] < nums[i - 1] && up) {
                    down = true;
                } else {
                    return false;
                }
            } 
            else if (down && !lup) {
                if (nums[i] < nums[i - 1]) continue;
                if (nums[i] > nums[i - 1]) lup = true;
                else return false;
            } 
            else {
                if (nums[i] <= nums[i - 1]) return false;
            }
        }
        return up && down && lup;
    }
};