#include<bits/stdc++.h>
using namespace std;
string s,t;
int dp[3005][3005];
int Rec(int i,int j,int s_len,int t_len){
	//pruning
	if(i == s_len || j == t_len) return 0;
	//base case
	//cache check
	if(dp[i][j] != -1) return dp[i][j];
	//transition
	int ans =0;
	ans = max(ans,Rec(i+1,j,s_len,t_len));
	ans = max(ans,Rec(i,j+1,s_len,t_len));
    if(s[i] == t[j]){
        ans = max(ans,1 + Rec(i+1,j+1,s_len,t_len));
    }
	//save && return
	return dp[i][j] = ans;
}
void generate(int i,int j,int s_len,int t_len){
     if(i == s_len || j == t_len) return;
     if(s[i] == t[j]){
         cout << s[i];
         generate(i+1, j+1, s_len, t_len);
     }
     else {
         if(dp[i+1][j] > dp[i][j+1]){
             generate(i+1, j, s_len, t_len);
         } else {
             generate(i, j+1, s_len, t_len);
         }
     }
}
void solve(){
  cin>>s>>t;
  int s_len = s.length();
  int t_len = t.length();
  memset(dp,-1,sizeof(dp));
   cout<<Rec(0,0,s_len,t_len)<<endl;
  // generate(0,0,s_len,t_len);
 //  cout<<"\n";
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}
