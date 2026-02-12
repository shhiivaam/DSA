class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();

        int max_length = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                bool ok = true;
                int val = -1;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] == 0)
                        continue;

                    if (val == -1) {
                        val = freq[k];
                    } else if (freq[k] != val) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    max_length = max(max_length, j - i + 1);
                }
            }

        }
         return max_length;
    }
};