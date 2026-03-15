class Solution {
public:
    long long  countCommas(long long n) {
        if (n < 1000) return 0;
        // long long cnt = 0;
        // long long k = n;
        // while (k) {
        //     cnt++;
        //     k /= 10;
        // }
        long long cc = 0;
        long long b = 1000;
        while (b <= n) {
            cc += (n - b + 1);
            b *= 1000;
        }
        return cc;
    }
};