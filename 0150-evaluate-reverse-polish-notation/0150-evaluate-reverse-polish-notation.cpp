#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& arr) {
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            if (isdigit(arr[i][0]) || (arr[i].size() > 1 && arr[i][0] == '-')) {
                int num = stoi(arr[i]);
                st.push(num);
            } else {
                if (st.size() >= 2) {
                    int b = st.top(); st.pop();
                    int a = st.top(); st.pop();

                    if (arr[i] == "*") {
                        st.push(a * b);
                    } else if (arr[i] == "/") {
                        st.push(a / b);
                    } else if (arr[i] == "^") {
                        st.push(pow(a, b)); 
                    } else if (arr[i] == "+") {
                        st.push(a + b);
                    } else if (arr[i] == "-") {
                        st.push(a - b);
                    }
                }
            }
        }
        return st.top();
    }
};