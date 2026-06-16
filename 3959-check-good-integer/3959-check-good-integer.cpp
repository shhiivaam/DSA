class Solution {
public:
    bool checkGoodInteger(int n) {
        long long dt_sum = 0;
        long long sqr_sum = 0;
        while(n > 0){
            int ld = n % 10;
            dt_sum += ld;
            sqr_sum += ld * ld;
            n /= 10;
        }
        return sqr_sum - dt_sum >= 50;
    }
};