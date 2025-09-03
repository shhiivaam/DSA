#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> sorted;
        for (int i = n - 1; i >= 0; i--) {
            auto it = lower_bound(sorted.begin(), sorted.end(), nums[i]);
            ans[i] = it - sorted.begin();
            sorted.insert(it, nums[i]);
        }
        return ans;
    }
};
