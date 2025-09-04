class Solution {
private:
bool isPalindrome(int i , int j, string& word){
    while(i < j){
        if(word[i++] != word[j--]) return false;
    }
   return true; 
}
int solve(int i , int n, string& word, vector<int>&Dp){
    if( i == n) return 0;
    if(Dp[i] != -1) return Dp[i];
    int minCost = INT_MAX;
    for(int j = i; j < n; j++){
        if(isPalindrome(i,j,word)){
            int cost = 1 + solve(j+1,n,word,Dp);
            minCost = min(minCost,cost);
        }
    }
return Dp[i] = minCost;
}    
public:
    int minCut(string s) {
       int n = s.length();
       vector<int>Dp(n,-1);
       return solve(0,n,s,Dp)-1;  
    }
};