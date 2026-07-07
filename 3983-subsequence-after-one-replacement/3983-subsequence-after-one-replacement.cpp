class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        if (n > m) return false;

        if (n == 1) return true;

        vector<int> L(n, m);
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < m && t[j] != s[i]) {
                j++;
            }
            if (j < m) {
                L[i] = j;
                j++;
            } else {
                break;
            }
        }
        vector<int> R(n, -1);
        j = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            while (j >= 0 && t[j] != s[i]) {
                j--;
            }
            if (j >= 0) {
                R[i] = j;
                j--;
            } else {
                break;
            }
        }
        if (L[n - 1] < m) return true;

        if (R[1] >= 1) return true;

        if (L[n - 2] <= m - 2) return true;

        for (int i = 1; i < n - 1; ++i) {
            if (R[i + 1] != -1 && L[i - 1] != m) {
                if (R[i + 1] - L[i - 1] >= 2) {
                    return true;
                }
            }
        }

        return false;
    }
};