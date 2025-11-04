#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        vector<int> rest;
        vector<int> vis(2005, 0);
        for (int i = 0; i < nums.size(); i++) vis[nums[i]] = 1;
        for (int j = 1; rest.size() < k; j++) {
            if (vis[j] == 0) rest.push_back(j);
        }
        return rest[k - 1];
    }
};
