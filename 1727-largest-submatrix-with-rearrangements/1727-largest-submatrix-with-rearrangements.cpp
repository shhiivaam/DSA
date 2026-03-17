class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0);
        int max_area = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1)
                    height[j] += 1;
                else
                    height[j] = 0;
            }
            vector<int> one = height;
            sort(one.rbegin(), one.rend());

            for (int j = 0; j < m; j++) {
                max_area = max(max_area, one[j] * (j + 1));
            }
        }

        return max_area;
    }
};