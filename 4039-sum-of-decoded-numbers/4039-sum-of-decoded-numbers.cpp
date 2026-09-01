class Solution {
private:
    const int MOD = 1e9 + 7;
    long long modPow(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int sumDecoded(vector<long long>& nums) {
        long long totalSum = 0;

        for (long long num : nums) {
            int width = num % 10;
            long long d = num / 10;
            string dStr = to_string(d);
            long long x = stoll(dStr.substr(0, width));
            long long y = stoll(dStr.substr(width));
            totalSum = (totalSum + modPow(x, y)) % MOD;
        }

        return totalSum;
    }
};