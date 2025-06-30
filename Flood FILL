#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
bool is_safe(vector<vector<int>>&mtx,int x,int y,int n,int m_col){
    return (x >=0 && x<n && y >= 0 && y<n && mtx[x][y] == m_col);
}
void bfs(int r,int c,vector<vector<int>>&mtx,vector<vector<int>>vis,int n,int nw,int m_col){
    queue<pair<int,int>>q;
    q.push({r,c});
    vis[r][c]=1;
    while(!q.empty()){
       int x = q.front().first;
       int y = q.front().second;
       q.pop();
        mtx[x][y] = nw;
       for(int k = 0; k<4;k++){
          int nr = x + dx[k];
          int nc = y + dy[k];
          if(is_safe(mtx,nr,nc,n,m_col) && !vis[nr][nc]){
              vis[nr][nc]=1;
              q.push({nr,nc});
          }
       }
    }
}
int main(){
    int n; cin>>n;
    vector<vector<int>>mtx(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mtx[i][j];
        }
    }
    int r,c;
    cin>>r>>c;
    int nw; cin>>nw;
    int m_col = mtx[r][c];
    vector<vector<int>>vis(n,vector<int>(n,0));
    bfs(r,c,mtx,vis,n,nw,m_col);
 for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mtx[i][j]<<" ";
        }
       cout<<endl; 
    }
}
