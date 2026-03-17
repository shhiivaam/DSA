class Solution {
public:
    bool solve(string& s1, string& s2, int i, int j, int len,
               vector<vector<vector<int>>>& dp) {

        if (dp[i][j][len] != -1) return dp[i][j][len];

        if (s1.substr(i, len) == s2.substr(j, len))
            return dp[i][j][len] = true;

        string a = s1.substr(i, len);
        string b = s2.substr(j, len);

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a != b)
            return dp[i][j][len] = false;

        for (int k = 1; k < len; k++) {
            if (solve(s1, s2, i, j, k, dp) &&
                solve(s1, s2, i + k, j + k, len - k, dp))
                return dp[i][j][len] = true;

            if (solve(s1, s2, i, j + len - k, k, dp) &&
                solve(s1, s2, i + k, j, len - k, dp))
                return dp[i][j][len] = true;
        }

        return dp[i][j][len] = false;
    }
    bool isScramble(string s1, string s2) {
        vector<int> freq(26, 0), freq1(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }
        for (int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
        }
        if(freq != freq1) return false;
        int n = s1.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(n + 1, -1)));

        return solve(s1, s2, 0, 0, n, dp);
    }
};