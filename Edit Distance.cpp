#include<bits/stdc++.h>
using namespace std;
string s,t;
void solve(){
  cin>>s>>t;
  int s_len = s.length();
  int t_len = t.length();
   memset(dp,-1,sizeof(dp));
   Rec(0,0,s_len,t_len);
   cout<<"\n";
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}
