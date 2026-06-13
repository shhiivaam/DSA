class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        
        string ans = "";
        for(auto v : words){
            int sum = 0;
            for(int i = 0; i < v.length(); i++){
                int ind = v[i] - 'a';
                sum += weights[ind];
            }
            sum %= 26;
            ans += char(122 - sum);
        }
        return ans;
    }
};