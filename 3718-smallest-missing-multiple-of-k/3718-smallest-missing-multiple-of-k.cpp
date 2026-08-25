class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> st;

        for (int x : nums) {
            if (x % k == 0) {
                st.insert(x / k);
            }
        }

        int expected = 1;

        for (int x : st) {
            if (x != expected) {
                return k * expected;
            }
            expected++;
        }

        return k * expected;
    }
};