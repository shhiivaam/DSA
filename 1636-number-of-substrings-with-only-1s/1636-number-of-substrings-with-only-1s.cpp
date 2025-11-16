class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1000000007;
        long long res = 0;
        long long cnt = 0; 
        for (char c : s) {
            if (c == '1') {
                cnt++; 
            } else {
                res = (res + (cnt * (cnt + 1) / 2) % MOD) % MOD;
                cnt = 0;
            }
        }
        if (cnt > 0) {
            res = (res + (cnt * (cnt + 1) / 2) % MOD) % MOD;
        }
        
        return (int)res;
    }
};
