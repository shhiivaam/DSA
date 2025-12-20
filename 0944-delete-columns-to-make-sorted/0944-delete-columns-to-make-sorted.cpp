class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int min = 0;
        int n = strs[0].length();
        for(int i = 0; i <  n ;i++){
            string temp ="";
            string org = "";
            for(int j = 0; j < strs.size();j++){
                temp = strs[j];
                org += temp[i];
            }
           temp = org;
           sort(temp.begin(),temp.end());
           if(temp != org){
                min++;
           }
        }
     return min;   
    }
};