class Solution {
public:
    int minSteps(string s, string t) {
       vector<int>freq(26,0);
       for(int i = 0; i < s.length();i++){
          freq[s[i]- 'a']++;
       }
       for(int i = 0; i < t.length(); i++){
           freq[t[i] - 'a']--;
       }
       int min_step=0;
       for(int i =0; i <26;i++){
          if(freq[i] == 0) continue;
          if(freq[i] < 0){
            min_step -= freq[i];
          }else{
              min_step += freq[i];
          }
       }
    return min_step / 2;
    }
};