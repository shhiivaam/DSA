class Solution {
public:
    int countHomogenous(string s) {
        long long ans = 0;
        int i = 0, n = s.size();
        int mod = 1e9 + 7;
        while (i < n) {
            int cnt = 0;
            while (i + 1 < n && s[i] == s[i + 1]) {
                cnt++;
                i++;
            }
            cnt++;
            ans = (ans + (1LL * cnt * (cnt + 1)) / 2) % mod;
            i++;
        }
        return ans;
    }
};