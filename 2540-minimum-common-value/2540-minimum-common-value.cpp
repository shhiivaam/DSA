class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return getCommon(nums2, nums1); 
        }
        for (int num : nums1) {
            if (binary_search(nums2.begin(), nums2.end(), num)) {
                return num; 
            }
        }
        return -1;
    }
};