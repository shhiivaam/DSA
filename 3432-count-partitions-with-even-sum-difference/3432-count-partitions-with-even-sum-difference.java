class Solution {
    public int countPartitions(int[] nums) {
        int count = 0  , sum = 0;

        for(int i : nums)
            sum += i;

        int currSum = 0;

        for(int i = 0 ; i<nums.length-1 ; i++){
            currSum += i;
            if((sum - 2*currSum) % 2 == 0)
                count++;
        }

        return count;
    }
}