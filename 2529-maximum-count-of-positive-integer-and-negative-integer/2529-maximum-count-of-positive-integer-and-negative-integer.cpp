class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int e,c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < 0){
                e++;
            }else if(nums[i] > 0){
                c++;
            }
        }
    return max(e,c);
    }
};