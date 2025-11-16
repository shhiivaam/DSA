class Solution {
    public int maximizeExpressionOfThree(int[] nums) {
        int n = nums.length;
        // Arrays.sort(nums);
        int a = Integer.MIN_VALUE , b = Integer.MIN_VALUE , c = Integer.MAX_VALUE;
        for(int x : nums){
            c = Math.min(c, x); 
            if (x > a) {
                b = a;
                a = x;
            } else if (x > b) {
                b = x;
            }
        }
        System.out.print(c);
        return a+b-c;
    }
}