class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long max_sum = 0;
        int neg = 0;  int mini = 1e8;  int zero = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] < 0)
                    neg++;
                max_sum += abs(matrix[i][j]);
                mini = min(abs(matrix[i][j]), mini);
                if (matrix[i][j] == 0)
                    zero++;
            }
        }
        if (neg % 2 == 0 || zero > 0) {
            return max_sum;
        } else {
            max_sum -= 2LL * mini;
        }
        return max_sum;
    }
};