class Solution {
public:
    bool isPalindrome(const string &s) {
        int lo = 0, hi = s.size() - 1;
        while(lo < hi) {
            if(s[lo++] != s[hi--]) return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        int n = words.size();
        for(int i = 0; i < n; i++){
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            mp[rev] = i;
        }
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            string word = words[i];
            int len = word.size();
            for(int j = 0; j <= len; j++){
                string left = word.substr(0, j);
                string right = word.substr(j);

                if(isPalindrome(left) && mp.count(right) && mp[right] != i){
                    ans.push_back({mp[right], i});
                }
                if(j != len && isPalindrome(right) && mp.count(left) && mp[left] != i){
                    ans.push_back({i, mp[left]});
                }
            }
        }
        return ans;
    }
};
