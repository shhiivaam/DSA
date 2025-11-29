class Solution {
public:
    int firstUniqChar(string s) {
        int state[26] = {0};
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            if (state[idx] == 0) {
                state[idx] = i + 1;
            } else {
                state[idx] = -1;
            }
        }
        int firstIdx = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (state[i] > 0) {
                if (state[i] < firstIdx) {
                    firstIdx = state[i];
                }
            }
        }
        return (firstIdx == INT_MAX) ? -1 : firstIdx - 1;
    }
};
