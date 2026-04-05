class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> freq(26, 0), freq2(10, 0);
        bool ch = false, num = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') continue;
            freq[s[i] - 'a']++;
            ch = true;
        }
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                freq2[s[i] - '0']++;
                num = true;
            }
        }

        int sum = 0;
        if (ch) {
            for (int i = 0; i < 13; i++) {
                sum += abs(freq[i] - freq[25 - i]);
            }
        }
        if (num) {
            for (int i = 0; i < 5; i++) {
                sum += abs(freq2[i] - freq2[9 - i]);
            }
        }
        return sum;
    }
};