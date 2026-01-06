class Solution {
public:
    bool is_dt(char ch) { return ch >= '0' && ch <= '9'; }
    bool isNumber(string s) {
        int n = s.length();
        if (s[0] == 'e' || s[0] == 'E' || s[n - 1] == 'e' || s[n - 1] == 'E')
            return false;
        if (n == 1 && s[0] == '.' || s[0] == 'e' || s[0] == ' E')
            return false;
          if (s[n-1] == '+' || s[n-1] == '-') return false;    
        bool sawe = false;
        bool sawE = false;
        bool plus = false;
        bool minus = false;
        bool sawdigit = false;
        int dot = 0;
        int e = 0;
        int E = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] >= '0' && s[i] <= '9')
                sawdigit = true;

            if (s[i] >= 'a' && s[i] <= 'z' && s[i] != 'e')
                return false;
            if (s[i] >= 'A' && s[i] <= 'Z' && s[i] != 'E')
                return false;

            if (s[i] == 'e') {
                e += 1;
                if (dot > 0)
                    return false;
                sawe = true;
            }
            if (s[i] == 'E') {
                sawE = true;
                if (dot > 0)
                    return false;
                E += 1;
            }
            if (s[i] == '.') {
                dot += 1;
            }
            if (s[i] == '.' && sawE || s[i] == '.' && sawe)
                return false;

            if (s[i] == '+') {
                plus = true;

                if (i < n - 1 && s[i + 1] == '-' || dot > 0)
                    return false;
                if (i < n - 1 && i > 0 && is_dt(s[i - 1]) && is_dt(s[i + 1]))
                    return false;
            }
            if (s[i] == '-') {
                minus = true;
                if (sawdigit)
                    return false;
                if (i < n - 1 && s[i + 1] == '+' || dot > 0)
                    return false;
                if (i > 0 && i < n - 1 && is_dt(s[i - 1]) && is_dt(s[i + 1]))
                    return false;
            }
        }
        return sawdigit && dot <= 1 && e <= 1 && E <= 1;
    }
};