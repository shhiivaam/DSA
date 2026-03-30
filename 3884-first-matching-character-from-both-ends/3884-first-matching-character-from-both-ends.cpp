class Solution {
public:
    int firstMatchingIndex(string s) {
        int hi = s.length() - 1;
        int lo = 0;
        if(s.length() == 1) return 0;
        while (lo <= hi) {
            if (s[lo] == s[hi])
                return lo;
            lo++, hi--;
        }
        // if (s.length() % 2 != 0)
        //     return 1;
        return -1;
    }
};