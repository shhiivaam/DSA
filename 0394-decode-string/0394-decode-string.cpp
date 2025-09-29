class Solution {
public:
    string decodeString(string s) {
        stack<int> numStk;
        stack<string> strStk;
        string curr = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                numStk.push(num);
                strStk.push(curr);
                num = 0;
                curr = "";
            }
            else if (c == ']') {
                int repeat = numStk.top(); numStk.pop();
                string prev = strStk.top(); strStk.pop();
                string temp = "";
                for (int i = 0; i < repeat; i++) {
                    temp += curr;
                }
                curr = prev + temp;
            }
            else { // letter
                curr += c;
            }
        }
        return curr;
    }
};
