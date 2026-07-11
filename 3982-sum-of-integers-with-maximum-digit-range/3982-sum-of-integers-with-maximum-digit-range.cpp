class Solution {
public:
    int digitRange(int x) {
        int mx = 0;
        int mn = 9;

        while (x > 0) {
            int d = x % 10;
            mx = max(mx, d);
            mn = min(mn, d);
            x /= 10;
        }

        return mx - mn;
    }

    int maxDigitRange(vector<int>& nums) {
        int maxRange = -1;
        int ans = 0;

        for (int num : nums) {
            int range = digitRange(num);

            if (range > maxRange) {
                maxRange = range;
                ans = num;
            } else if (range == maxRange) {
                ans += num;
            }
        }

        return ans;
    }
};