class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        for(auto v : letters){
            if(v > target){
                ans = v;
                break;
            }
        }
        return ans;
    }
};