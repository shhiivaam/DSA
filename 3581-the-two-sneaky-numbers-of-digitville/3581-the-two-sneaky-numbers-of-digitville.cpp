class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            for(int j =i+1;j<nums.size();j++){
                if(nums[i] == nums[j]){
                    ans.push_back(nums[i]);
                    cnt++;
                }
                if(cnt > 2) break;
            }
        }
    return ans;
    }
};