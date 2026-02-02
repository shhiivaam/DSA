class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long current_sum = 0;
        long long min_sum = -1;
        multiset<int> L, R;
        int n = nums.size();
        int target = k - 1;
        
        for (int i = 1; i < n; ++i) {
            L.insert(nums[i]);
            current_sum += nums[i];
            if (L.size() > target) {
                int max_val = *L.rbegin();
                L.erase(prev(L.end()));
                current_sum -= max_val;
                R.insert(max_val);
            }
            if (i > dist + 1) {
                int out_val = nums[i - (dist + 1)];
                auto it_r = R.find(out_val);
                if (it_r != R.end()) {
                    R.erase(it_r);
                } else {
                    auto it_l = L.find(out_val);
                    if (it_l != L.end()) {
                        L.erase(it_l);
                        current_sum -= out_val;
                        if (!R.empty()) {
                            int min_r = *R.begin();
                            R.erase(R.begin());
                            L.insert(min_r);
                            current_sum += min_r;
                        }
                    }
                }
            }
            if (L.size() == target) {
                if (min_sum == -1 || current_sum < min_sum) {
                    min_sum = current_sum;
                }
            }
        }
        return min_sum + nums[0];
    }
};