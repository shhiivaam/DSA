class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
      int maxi = *max_element(nums.begin(),nums.end());
      int mini = *min_element(nums.begin(),nums.end());
       
       if(maxi > 0){
         maxi -= k;
       }else{
         maxi += k;
       }
       if(mini >= 0){
          mini += k;
       }else{
         mini -= k;
       }
  if(mini > maxi) return 0;
   return maxi - mini;
    }
};