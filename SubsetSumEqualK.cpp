#include<bits/stdc++.h>
using namespace std;
int arr[10010];
int n,k;
int dp[1000][1000];
bool rec(int level,int csum){
	if(level == n){
		if(csum == 0){
			return 1;
		}else{
			return 0;
		}
	} 
	if(dp[level][csum] != -1) return dp[level][csum];
	//Transition
	int pick = rec(level+1,csum);
	if(csum-arr[level] >= 0 || csum >= arr[level]){
		pick = pick || rec(level+1,csum-arr[level]);
	}

	return  dp[level][csum]=pick;
}
void Sol(){
   cin>>n>>k;
   for(int i=0;i<n;i++) cin>>arr[i];
   memset(dp,-1,sizeof(dp));
   if(rec(0,k)){
   	  cout<<"True"<<endl;
   }else{
   	 cout<<"False"<<endl;
   }

}
int main(){
	int t;
	cin>>t;
	while(t--) Sol();
}
