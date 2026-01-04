class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
       int sum = 0;
       for(int i = 0; i < nums.size(); i++){
           int j = 2;
           if(nums[i] % 2 == 0) j = 2;
           else j = 3;
           int div = 2;
           int temp_sum = nums[i] + 1;
           for(j ; j <= nums[i] / 2; j++){
              if(nums[i] % j == 0){
                 div++;
                 if(div > 4) break;
                 temp_sum += j;
              }
           }
        if(div == 4)
        sum += temp_sum;
       } 
    return sum;
    }
};