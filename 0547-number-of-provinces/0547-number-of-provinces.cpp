class Dsu{
    public:
    vector<int> parent, size;
    Dsu(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findpar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findpar(parent[node]);
    }
    void RankBySize(int u, int v) {
        int ult_u = findpar(u);
        int ult_v = findpar(v);
        if (ult_u == ult_v) return;
        if (size[ult_u] < size[ult_v]) {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        } else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
         Dsu ds(n);
       for(int i=0;i<n;i++){
          for(int j =0;j<n;j++){
            if(isConnected[i][j] == 1 ){
                ds.RankBySize(i,j);
            }
          }
       }
       int cnt =0;
        for(int i=0;i<n;i++){
        if(ds.findpar(i) == i) cnt++;
        }
    return cnt;
    }
};