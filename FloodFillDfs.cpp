#include<iostream>
#include<vector>
using namespace std;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
bool is_safe(vector<vector<int>>&mtx,int x,int y,int n,int m_col){
    return (x>=0 && x<n && y>= 0 && y<n && mtx[x][y] == m_col);
}
void dfs(int r,int c,vector<vector<int>>&mtx,vector<vector<int>>vis,int n,int nw,int m_col){
     if(vis[r][c] == 1 || mtx[r][c] == 0) {
        return;
    }
    mtx[r][c]=nw; 
    vis[r][c] = 1;
    for(int k=0;k<4;k++){
     int x  = r + dx[k];
     int y  = c + dy[k]; 
    if(is_safe(mtx,x,y,n,m_col) && !vis[x][y]){
        dfs(x,y,mtx,vis,n,nw,m_col);
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
    dfs(r,c,mtx,vis,n,nw,m_col);
 for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mtx[i][j]<<" ";
        }
       cout<<endl; 
    }
}
