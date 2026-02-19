class Solution {
public:
    int countBinarySubstrings(string s) {
       int prev = 0;      
        int curr = 1; 
        int total = 0;

        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i-1]) {
                curr++;
            } else {
                total += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }

        total += min(prev, curr);
        return total;
    }
};