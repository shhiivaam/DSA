class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int _inc = 1;
        int max_len = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                _inc++;
            } else {
                _inc = 1;
            }
            max_len = max(_inc, max_len);
        }
        int _inc2 = 1;
        int max_len2 = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                _inc2++;
            } else {
                _inc2 = 1;
            }
            max_len2 = max(_inc2, max_len2);
        }
        max_len = min(max_len, max_len2);
        max_len += 1;
        return max_len * max_len;
    }
};