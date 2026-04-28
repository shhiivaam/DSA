class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> array;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                array.push_back(grid[i][j]);
            }
        }
        sort(array.begin(), array.end());
        int target = array[array.size() / 2];
        int min_step = 0;
        for (int i = 0; i < array.size(); i++) {
            if (abs(target - array[i]) % x != 0)
                return -1;
            min_step += abs(target - array[i]) / x;
        }
        return min_step;
    }
};