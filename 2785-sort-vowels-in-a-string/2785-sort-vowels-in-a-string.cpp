class Solution {
public:
     bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    string sortVowels(string s) {
        unordered_map<char , int>mp;
        for(auto c : s)
            if(isVowel(c))
                mp[c]++;
        
        int j = 0 ;
        string str = "AEIOUaeiou" ;
        for(int i = 0 ; i <s.size() ; i++){
            if(isVowel(s[i])){             
                while(j < str.size() && mp[str[j]] == 0)
                    j++;
                s[i] = str[j] ;
                mp[str[j]]-- ;
            }
        }

        return s ;
    }
};