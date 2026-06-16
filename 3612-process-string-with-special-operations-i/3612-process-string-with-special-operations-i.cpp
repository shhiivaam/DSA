class Solution {
public:
    string processStr(string s) {
       string ans = "";
       for(auto v : s){
         if(v >='a' && v <= 'z'){
            ans += v;
         }else if(v == '*' && ans.length() > 0){
            ans.pop_back();
         }else if(v == '#' && ans.length() > 0){
             string temp = ans;
             ans += temp;
         }else if(v == '%' && ans.length() > 0){
            reverse(ans.begin(),ans.end());
         }else{
            continue;
         }
       } 
       return ans;
    }
};