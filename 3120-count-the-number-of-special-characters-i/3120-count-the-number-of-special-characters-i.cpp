class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt = 0;
        set<char> l_st;
        set<char> used;
        for (auto v : word) {
            if (v >= 'A' && v <= 'Z') {
                l_st.insert(v);
            }
        }
        for (auto ch : word) {
            if (ch >= 'a' && ch <= 'z') {
                char cc = char(ch - 32);
                if (l_st.find(cc) != l_st.end() &&
                    used.find(ch) == used.end()) {
                    cnt++;
                    used.insert(ch);
                }
            }
        }
        return cnt;
    }
};