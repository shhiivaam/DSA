class Solution {
public:
    int dp[301][27][27];

    int dist(int a, int b) {
        if (a == 26 || b == 26)
            return 0;
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int solve(string& word, int i, int f1, int f2) {
        if (i == word.size())
            return 0;

        if (dp[i][f1][f2] != -1)
            return dp[i][f1][f2];

        int cur = word[i] - 'A';

        int useFirst = dist(f1, cur) + solve(word, i + 1, cur, f2);
        int useSecond = dist(f2, cur) + solve(word, i + 1, f1, cur);

        return dp[i][f1][f2] = min(useFirst, useSecond);
    }

    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(word, 0, 26, 26);
    }
};