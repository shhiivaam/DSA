class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        ans.push_back(nums[0]);
        int maxi = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] == 1 && nums[i-1] < nums[i]){
                ans.push_back(nums[i]);
            }else if(nums[i] > maxi){
                 ans.push_back(nums[i]);
            }else{
                int maxii = -1;
                for(int k = i + 1; k < n; k++){
                    maxii = max(maxii,nums[k]);
                }
                if(nums[i] > maxii){
                    ans.push_back(nums[i]);
                }
            }
            maxi = max(maxi, nums[i]);
        }
    return ans;
    }
};