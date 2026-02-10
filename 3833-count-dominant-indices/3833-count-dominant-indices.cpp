class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int ele = 0;
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        vector<int>avg(n);
        for(int i = 1; i < n; i++){
            sum -= nums[i-1];
            avg[i-1] = sum / (n-i);
        }
        for(int i = 0; i < n; i++){
            if(nums[i] > avg[i]){
                ele++;
            }
        }
        return ele - 1;
    }
};