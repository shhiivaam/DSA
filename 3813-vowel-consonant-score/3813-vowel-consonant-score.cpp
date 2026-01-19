class Solution {
public:
    int vowelConsonantScore(string s) {
      int v = 0;
      int cons = 0;
       for(char ch : s){
         if(ch =='a' || ch =='e' || ch == 'i' || ch =='o' || ch == 'u'){
             v++;
         }
         else if(ch >= 'a' && ch <= 'z'){
            cons++;
         }
       }  
       if(v == 0 || cons == 0) return 0;
       return floor( v / cons);
    }
};