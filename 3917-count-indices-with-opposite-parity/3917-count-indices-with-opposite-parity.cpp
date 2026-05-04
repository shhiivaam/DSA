class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int>ans;
        for(int i = 0; i < nums.size(); i++){
            int cnt = 0;
            int idx = i + 1;
            for(int j = i + 1; j < nums.size(); j++){
                if(idx % 2 == 0 && nums[j] % 2 != 0){
                    cnt++;
                }
                if(idx % 2 != 0 && nums[j] % 2 == 0){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};