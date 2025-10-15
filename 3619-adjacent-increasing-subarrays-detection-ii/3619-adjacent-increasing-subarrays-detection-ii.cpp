#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, prev = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            cur++;
            if (i == n - 1 || nums[i] >= nums[i + 1]) {
                ans = max(ans, cur / 2);
                ans = max(ans, min(prev, cur));
                prev = cur;
                cur = 0;
            }
        }
        return ans;
    }
};
