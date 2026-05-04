class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;

        if (n % 2 == 0 || n % 3 == 0) return false;

        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }

    int sumOfPrimesInRange(int n) {
        int st = n;
        int rev = 0;
        while (n != 0) {
            int digit = n % 10;
            rev = rev * 10 + digit;
            n /= 10;
        }

        if (st > rev) swap(st, rev);

        long long sum = 0;

        for (int i = st; i <= rev; i++) {
            if (isPrime(i)) {
                sum += i;
            }
        }

        return sum;
    }
};