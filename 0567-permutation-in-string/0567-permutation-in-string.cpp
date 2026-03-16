class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        int n = s1.length();
        int m = s2.length();

        for (int i = 0; i < n; i++) {
            freq[s1[i] - 'a']++;
        }

        for (int i = 0; i < m; i++) {
            if (i + n > m) return false;
            vector<int> temp(26, 0);
            for (int k = i; k < i + n; k++) {
                temp[s2[k] - 'a']++;
            }
            if (freq == temp)
                return true;
        }

        return false;
    }
};