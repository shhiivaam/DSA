class Solution {
public:
    bool check(string& s, string& w) {
        if (s.size() != w.size() + 1) return false;
        int first = 0, second = 0;
        while (first < s.size()) {
            if (second < w.size() && s[first] == w[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }
        return second == w.size(); 
    }

    static bool comp(string& s, string& w) { 
        return s.size() < w.size(); 
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (check(words[i], words[prev]) && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
