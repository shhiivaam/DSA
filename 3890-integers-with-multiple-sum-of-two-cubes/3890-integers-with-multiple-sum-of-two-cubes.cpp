class Solution {
public:
    vector<int> findGoodIntegers(int n) {
         int lorqavined = n; 
        unordered_map<long long, int> mp;
        int limit = cbrt(n);
        for (long long a = 1; a <= limit; a++) {
            long long a3 = a * a * a;
            for (long long b = a; b <= limit; b++) {
                long long sum = a3 + b * b * b;
                if (sum > n) break;
                mp[sum]++;
            }
        }
        vector<int> result;
        for (auto &it : mp) {
            if (it.second >= 2) {
                result.push_back(it.first);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};