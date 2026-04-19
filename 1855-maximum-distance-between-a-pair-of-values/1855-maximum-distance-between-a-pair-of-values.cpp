class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums2.size();

        for (int i = 0; i < nums1.size(); i++) {
            int low = i, high = n - 1;
            int best = i - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (nums2[mid] >= nums1[i]) {
                    best = mid;
                    low = mid + 1; 
                } else {
                    high = mid - 1;
                }
            }

            ans = max(ans, best - i);
        }

        return ans;
    }
};