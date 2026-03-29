class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if (s1 == s2) {
            return true;
        } else {
            int k = 2;
            for (int i = 0; i < 4; i++) {
                if (s1[i] != s2[i] && k < 4) {
                    swap(s1[i], s1[k]);
                }
                k++;
            }
        }
        return s1 == s2;
    }
};