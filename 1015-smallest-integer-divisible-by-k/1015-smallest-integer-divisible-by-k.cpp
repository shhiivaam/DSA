class Solution {
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
    long long getPhi(long long n) {
        long long result = n;
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                while (n % i == 0)
                    n /= i;
                result -= result / i;
            }
        }
        if (n > 1)
            result -= result / n;
        return result;
    }
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        long long m = 9LL * k;
        long long phi = getPhi(m);
        vector<long long> divisors;
        for (long long i = 1; i * i <= phi; i++) {
            if (phi % i == 0) {
                divisors.push_back(i);
                if (i * i != phi) divisors.push_back(phi / i);
            }
        }
        sort(divisors.begin(), divisors.end());
        for (long long d : divisors) {
            if (power(10, d, m) == 1) return d;
        }
        return -1;
    }
};