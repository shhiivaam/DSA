class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int rem = sum % p;
        if(rem == 0) return 0;
        unordered_map<int,int> mp; 
        mp[0] = -1;
        long long prefix = 0;
        int ans = nums.size();

        for(int i = 0; i < nums.size(); i++){
            prefix += nums[i];
            int cur = prefix % p;
            int target = (cur - rem + p) % p;
            if(mp.find(target) != mp.end()){
                ans = min(ans, i - mp[target]);
            }
            mp[cur] = i;
        }
        return ans == nums.size() ? -1 : ans;
    }
};