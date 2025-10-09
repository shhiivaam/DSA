class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans = "";
        int a_cnt = 0, b_cnt = 0;
        while (a > 0 || b > 0) {
            if ((a > b && a_cnt < 2) || b_cnt == 2) {
                ans += 'a';  a--;  a_cnt++; b_cnt = 0; 
            } 
            else if (b > 0) {
                ans += 'b'; b--; b_cnt++; a_cnt = 0;
            } 
            else {
                break; 
            }
        }
        return ans;
    }
};
