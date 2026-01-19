class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                pref[i][j] = mat[i-1][j-1]
                           + pref[i-1][j]
                           + pref[i][j-1]
                           - pref[i-1][j-1];
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                for(int len = ans + 1; 
                    i + len - 1 <= n && j + len - 1 <= m; 
                    len++) {

                    int sum = pref[i+len-1][j+len-1]
                            - pref[i-1][j+len-1]
                            - pref[i+len-1][j-1]
                            + pref[i-1][j-1];

                    if(sum <= threshold)
                        ans = len;
                    else
                        break;
                }
            }
        }
        return ans;
    }
};
