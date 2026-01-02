class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
      int n = nums.size();
      map<int,int>mp;
      for(int i = 0; i < n; i++){
          mp[nums[i]]++;
      }  
      for(auto &[u,v] : mp){
         if(v == n / 2)
         return u;
      }
    return -1;
    }
};