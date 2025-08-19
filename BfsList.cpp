#include<iostream>
#include<queue>
using namespace std;
vector<vector<int>>gp;
vector<int>vis;
int cmp;
void bfs(int src){
   queue<int>q;
   q.push(src);
   vis[src]=1;
   while(!q.empty()){
      int node = q.front();
      q.pop();
     cout<<node<<" ";
    for(auto v : gp[node]){
        if(!vis[v]){
            vis[v]=1;
            q.push(v);
        }
     }
   }
}
int main(){
    int n,m;  cin>>n>>m;
    gp.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        gp[a].push_back(b);
        gp[b].push_back(a);
    }
   vis.assign(n+1,0); 
   bfs(0);
}
