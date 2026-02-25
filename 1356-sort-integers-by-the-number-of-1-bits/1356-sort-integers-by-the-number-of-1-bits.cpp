class Solution {
public:
    static int getSetBit(int n) {
        int c = 0;
        while (n) {
            n = n & (n - 1);
            c++;
        }
        return c;
    }
    vector<int> sortByBits(vector<int>& arr) {
        auto customComparator = [](int a, int b) {
            int x = getSetBit(a);
            int y = getSetBit(b);
            if (x == y)
                return a < b;
            return x < y;
        };
        sort(arr.begin(), arr.end(), customComparator);
        return arr;
    }
};