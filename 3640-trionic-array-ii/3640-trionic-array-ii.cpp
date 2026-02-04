class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long n = nums.size();
        const long long INF = 1e18; 
        
        long long s0 = nums[0];
        long long s1 = -INF;
        long long s2 = -INF;
        long long s3 = -INF;
        
        long long max_sum = -INF;
        
        for (int i = 1; i < n; ++i) {
            long long x = nums[i];
            long long prev = nums[i-1];
            
            long long next_s0 = -INF;
            long long next_s1 = -INF;
            long long next_s2 = -INF;
            long long next_s3 = -INF;
            
            if (x > prev) {
                next_s0 = max(x, s0 + x);
                
                if (s0 != -INF) next_s1 = s0 + x;
                
                long long candidate1 = (s2 != -INF) ? s2 + x : -INF;
                long long candidate2 = (s3 != -INF) ? s3 + x : -INF;
                next_s3 = max(candidate1, candidate2);
                
                next_s2 = -INF;
                
            } else if (x < prev) {
                next_s0 = x;
                
                long long candidate1 = (s1 != -INF) ? s1 + x : -INF;
                long long candidate2 = (s2 != -INF) ? s2 + x : -INF;
                next_s2 = max(candidate1, candidate2);
                
                next_s1 = -INF;
                next_s3 = -INF;
                
            } else {
                next_s0 = x;
                next_s1 = -INF;
                next_s2 = -INF;
                next_s3 = -INF;
            }
            
            s0 = next_s0;
            s1 = next_s1;
            s2 = next_s2;
            s3 = next_s3;
            
            if (s3 != -INF) {
                max_sum = max(max_sum, s3);
            }
        }
        
        return max_sum;
    }
};