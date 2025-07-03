class Solution {
public:
void kth(int lev,int k, string&s){
   if(lev == k){
      return;
   }
    char ch = s[lev]+'a';
     s += ch;
     kth(lev+1,k,s);
}
    char kthCharacter(int k) {
    string s="";
      kth(0,k,s);
      cout<<s;
      return 'a';  
    }
};
