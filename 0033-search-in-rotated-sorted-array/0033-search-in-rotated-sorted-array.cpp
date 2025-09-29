class Solution {
private:
    bool check(int mid, const vector<int>& nums, int target, int lo) {
        int n = nums.size();
        if (nums[lo] <= nums[mid]) { 
            return (nums[lo] <= target && target < nums[mid]);
        } else {
            return !(nums[mid] < target && target <= nums[n-1]);
        }
    }    
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int ans = -1;
        while (lo <= hi) {
           const int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                ans = mid;
                break;
            }
            if (check(mid, nums, target, lo)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans; 
    }
};
