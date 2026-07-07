// class Solution {
// public:
//     long long sumAndMultiply(int n) {
//         string s = to_string(n);
//         long long sum = 0;
//         string ans = "";

//         for (int i = 0; i < s.length(); i++) {
//             if (s[i] > '0' && s[i] <= '9') {
//                 ans += s[i];
//                 sum += s[i] - '0';
//             }
//         }

//         long long x = ans.empty() ? 0 : stoll(ans);
//         return x * sum;
//     }
// };
class Solution {
    public:
        long long sumAndMultiply(int n) {
            long long x = 0;
            int r = 1;
            int sum_digits = 0;
            while (n > 0) {
                int d = n % 10;
                n /= 10;
                if (d == 0) continue;
                x = d * r + x;
                sum_digits += d;
                r *= 10;
            }
            return x * sum_digits;
        }
};