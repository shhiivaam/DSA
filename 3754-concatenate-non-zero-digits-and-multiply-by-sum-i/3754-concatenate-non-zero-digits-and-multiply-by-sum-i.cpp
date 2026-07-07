class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        long long sum = 0;
        string ans = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] > '0' && s[i] <= '9') {
                ans += s[i];
                sum += s[i] - '0';
            }
        }

        long long x = ans.empty() ? 0 : stoll(ans);
        return x * sum;
    }
};