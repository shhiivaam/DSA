class Solution {
public:
    string generateString(string str1, string str2) {
      int n = str1.length();
        int m = str2.length();
        int L = n + m - 1;
        string word(L, '?');
        vector<bool> fixed(L, false);
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; ++j) {
                    if (word[i + j] != '?' && word[i + j] != str2[j]) {
                        return ""; 
                    }
                    word[i + j] = str2[j];
                    fixed[i + j] = true;
                }
            }
        }
        for (int i = 0; i < L; ++i) {
            if (word[i] == '?') {
                word[i] = 'a';
            }
        }
        auto checkF = [&]() {
            for (int i = 0; i < n; ++i) {
                if (str1[i] == 'F') {
                    bool match = true;
                    for (int j = 0; j < m; ++j) {
                        if (word[i + j] != str2[j]) {
                            match = false;
                            break;
                        }
                    }
                    
                    if (match) {
                        bool changed = false;
                        for (int j = m - 1; j >= 0; --j) {
                            if (!fixed[i + j]) {
                                for (char c = 'b'; c <= 'z'; ++c) {
                                    if (c != str2[j]) {
                                        word[i + j] = c;
                                        changed = true;
                                        break;
                                    }
                                }
                            }
                            if (changed) break;
                        }
                        if (!changed) return false; 
                        i = max(-1, i - m); 
                    }
                }
            }
            return true;
        };

        if (!checkF()) return "";

        return word;  
    }
};