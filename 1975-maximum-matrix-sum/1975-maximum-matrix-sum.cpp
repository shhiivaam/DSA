class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long max_sum = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> neg;
        int mini = 1e8;
        int zero = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] < 0) {
                    int ele = matrix[i][j];
                    ele *= -1;
                    neg.push_back(ele);
                }
                if(matrix[i][j] > 0) max_sum += matrix[i][j];
                mini = min(abs(matrix[i][j]), mini);
                if (matrix[i][j] == 0)
                    zero++;
            }
        }
        int len = neg.size();
        if (len % 2 == 0 || zero > 0) {
            max_sum += accumulate(neg.begin(), neg.end(), 0LL);
        } else {
            max_sum += accumulate(neg.begin(), neg.end(), 0LL);
            max_sum -= 2LL * mini;
        }
        return max_sum;
    }
};