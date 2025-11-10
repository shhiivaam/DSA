#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;
        stack<int> st;
        st.push(0);

        for (int x : nums) {
            while (!st.empty() && st.top() > x) {
                st.pop();
            }
            if (st.empty() || st.top() < x) {
                operations++;
                st.push(x);
            }
        }
        return operations;
    }
};
