class Solution {
    static boolean check(int[] nums, int[][] queries , int k){
        int []diff = new int[nums.length];
        
        for(int i = 0 ; i<= k ; i++){
            int l = queries[i][0] , r = queries[i][1] ;
            diff[l]++;
            if (r + 1 < nums.length)
                diff[r + 1]--;
        }
        int sum = 0;
        for(int i = 0 ; i<nums.length ; i++){
            sum += diff[i];
            diff[i] = sum ;
            if(nums[i] - diff[i] > 0)  
                return false;
        }
        return true;
    }
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int q = queries.length, n = nums.length;
        boolean flag = false;
       for (int i : nums) {
            if (i > 0) {
                flag = true;
                break;
            }
        }
        if (!flag)
            return true;
        int l = 0 , h = q-1;
        while(l <= h){
            int m = l + (h - l) / 2;
            if (check(nums, queries, m)) {
                return true;
            } else {
                l = m + 1;
            }
        }
        return false;
    }
}