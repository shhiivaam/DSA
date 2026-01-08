class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            int ele = i;
            bool ok = true;
            while (ele > 0) {
                int ld = ele % 10;
                if (ld == 0 || i % ld != 0) {
                    ok = false;
                    break;
                }
                ele /= 10;
            }
            if (ok) ans.push_back(i);
        }
        return ans;
    }
};
