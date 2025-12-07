class Solution {
    public boolean hasTrailingZeros(int[] nums) {
        int count = 0;
        for(int i : nums){
            if((i & 1) == 0)
                count++;
        }
        return count >= 2;
    }
}