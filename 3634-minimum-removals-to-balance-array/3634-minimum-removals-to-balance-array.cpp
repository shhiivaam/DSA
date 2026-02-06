class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = n;

        for (int i = 0; i < n; i++) {
            long long limit = 1LL * nums[i] * k;
            int lo = i, hi = n - 1;
            int index = i;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (nums[mid] <= limit) {
                    index = mid;     
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            int kept = index - i + 1;
            ans = min(ans, n - kept);
        }

        return ans;
    }
};
