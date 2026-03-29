class Solution {
public:
    string reversePrefix(string s, int k) {
       string ans = s.substr(0,k);
       reverse(ans.begin(),ans.end());
       ans += s.substr(k,s.length()); 
       return ans;
    }
};