class Solution {
public:
    string customSortString(string order, string s) {
        int freq[26] = {0};
        for(auto c : s)
            freq[c-'a']++;

        string ans ;
        for(auto c : order){
            while(freq[c-'a']){
                ans += c;
                freq[c-'a']--;
            }
        }
        for(int i = 0 ; i<26 ; i++){
            while(freq[i]){
                ans += (char)i+'a';
                freq[i]--;
            }
        }

        return ans;
    }
};