class Solution {
public:
    const double EPS = 1e-6;

    bool solve(vector<double> nums) {
        int n = nums.size();
        if (n == 1) {
            return fabs(nums[0] - 24) < EPS;
        }

        // Pick two numbers i, j
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                vector<double> next;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }

                // Try all 4 operations
                if (i < j) { // avoid duplicate for commutative ops
                    next.push_back(nums[i] + nums[j]);
                    if (solve(next)) return true;
                    next.pop_back();

                    next.push_back(nums[i] * nums[j]);
                    if (solve(next)) return true;
                    next.pop_back();
                }

                next.push_back(nums[i] - nums[j]);
                if (solve(next)) return true;
                next.pop_back();

                if (fabs(nums[j]) > EPS) { // avoid division by zero
                    next.push_back(nums[i] / nums[j]);
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }
};
