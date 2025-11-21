class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        int answer = 0;
        for (int ch = 0; ch < 26; ch++) {
            int l = first[ch], r = last[ch];
            if (l == -1 || l == r) continue; 
            vector<bool> seen(26, false);

            for (int i = l + 1; i < r; i++) {
                seen[s[i] - 'a'] = true;
            }

            answer += count(seen.begin(), seen.end(), true);
        }
        return answer;
    }
};
