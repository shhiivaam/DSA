class Solution {
public:
    bool hasSameDigits(string s) {
          while (s.size() > 2) {
            string t = "";
            for (int i = 0; i < s.size() - 1; i++) {
                int a = s[i] - '0';
                int b = s[i + 1] - '0';
                t += to_string((a + b) % 10);
            }
            s = t;
        }
        return s[0] == s[1];
    }
};