#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n+1, 0); 
        dp[1] = 1; 
        long long sharing = 0; 
        for (int day = 2; day <= n; day++) {
            if (day - delay >= 1) sharing = (sharing + dp[day - delay]) % MOD;
            if (day - forget >= 1) sharing = (sharing - dp[day - forget] + MOD) % MOD;
            dp[day] = sharing;
        }
        long long result = 0;
        for (int day = n - forget + 1; day <= n; day++) {
            if (day >= 1) result = (result + dp[day]) % MOD;
        }

        return result;
    }
};
