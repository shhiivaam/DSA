class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long sumOdd = 0;
        long long sumEven = 0;
        int cnt = 0;
        for (int i = 1; i <= 100000; i++) {
            if (cnt == 2 * n) break;
            if (i % 2 == 0)
                sumEven += i;
            else
                sumOdd += i;

            cnt++;
        }
        return __gcd(sumOdd, sumEven);
    }
};