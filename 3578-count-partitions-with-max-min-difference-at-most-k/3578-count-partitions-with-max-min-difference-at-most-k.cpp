class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n + 1, 0);
        vector<long long> pref(n + 2, 0);
        
        dp[0] = 1;
        pref[1] = 1;
        
        deque<int> max_d, min_d;
        int left = 0;
        int mod = 1e9 + 7;
        
        for (int i = 0; i < n; ++i) {
            while (!max_d.empty() && nums[max_d.back()] <= nums[i]) 
                max_d.pop_back();
            max_d.push_back(i);
            
            while (!min_d.empty() && nums[min_d.back()] >= nums[i]) 
                min_d.pop_back();
            min_d.push_back(i);
            
            while (nums[max_d.front()] - nums[min_d.front()] > k) {
                left++;
                if (max_d.front() < left) max_d.pop_front();
                if (min_d.front() < left) min_d.pop_front();
            }
            
            long long current_ways = (pref[i + 1] - pref[left] + mod) % mod;
            dp[i + 1] = current_ways;
            pref[i + 2] = (pref[i + 1] + current_ways) % mod;
        }
        
        return dp[n];
    }
};