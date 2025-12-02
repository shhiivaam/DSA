#include <bits/stdc++.h>
using namespace std;
static const long long MOD = 1e9 + 7;
long long C2(long long k) {
    if (k < 2) return 0;
    return (k * (k - 1) / 2) % MOD;
}
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long, long long> freq;
        freq.reserve(points.size() * 2);

        for (auto &p : points) freq[p[1]]++;

        vector<long long> a;
        a.reserve(freq.size());
        for (auto &pr : freq) a.push_back(C2(pr.second));

        long long sumA = 0, sumA2 = 0;
        for (long long x : a) {
            sumA = (sumA + x) % MOD;
            sumA2 = (sumA2 + (x * x) % MOD) % MOD;
        }

        long long ans = ((sumA * sumA) % MOD - sumA2 + MOD) % MOD;
        long long inv2 = (MOD + 1) / 2;
        ans = (ans * inv2) % MOD;

        return (int)ans;
    }
};
