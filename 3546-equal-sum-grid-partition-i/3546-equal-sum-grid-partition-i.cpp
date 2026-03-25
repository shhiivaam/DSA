class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += grid[i][j];
            }
        }
        if (sum % 2 != 0)
            return false;

        long long  c_sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                c_sum += grid[i][j];
                 if ((c_sum * 2) == sum)
                     return true;
            }
            if((c_sum * 2) > sum) break;
        }
        c_sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                c_sum += grid[j][i];
                if ((c_sum * 2) == sum)
                    return true;
            }
            if((c_sum * 2) > sum) break;
        }
        return false;
    }
};