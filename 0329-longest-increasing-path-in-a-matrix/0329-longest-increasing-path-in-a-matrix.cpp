class Solution {
public:
int dfs(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&vis,int n, int m){
  vis[i][j] = 1;
  int dx[]={0,0,1,-1};
  int dy[]={1,-1,0,0};
  int ans = 1;
  for(int k = 0; k < 4; k++){
    int nx = i + dx[k];
    int ny = j + dy[k];
    if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && matrix[nx][ny] > matrix[i][j]){
         ans = max(ans,1 + dfs(nx,ny,matrix,vis,n,m));
     }
  } 
  return ans;
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = -1;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                vector<vector<int>>vis(n,vector<int>(m,0));
                int maxi = dfs(i,j,matrix,vis,n,m);
                ans = max(ans,maxi);
            }
        }
      return ans;  
    }
};