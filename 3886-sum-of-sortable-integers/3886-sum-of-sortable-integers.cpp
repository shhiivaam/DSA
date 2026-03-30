class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        vector<bool> valid_boundary(n + 1, false);
        vector<int> diff(100005, 0);
        int non_zero_count = 0;

        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            if (diff[num] == 0) non_zero_count++;
            diff[num]++;
            if (diff[num] == 0) non_zero_count--;

            int s_num = sorted_nums[i];
            if (diff[s_num] == 0) non_zero_count++;
            diff[s_num]--;
            if (diff[s_num] == 0) non_zero_count--;

            if (non_zero_count == 0) {
                valid_boundary[i + 1] = true;
            }
        }

        vector<int> prefD(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            prefD[i + 1] = prefD[i] + (nums[i] > nums[i + 1] ? 1 : 0);
        }

        int sum_k = 0;
        for (int k = 1; k <= n; ++k) {
            if (n % k == 0) {
                bool is_sortable = true;
                for (int j = 0; j < n / k; ++j) {
                    int start = j * k;
                    int end = start + k - 1;

                    if (!valid_boundary[end + 1]) {
                        is_sortable = false;
                        break;
                    }

                    int internal_drops = prefD[end] - prefD[start];
                    int wrap_drop = (nums[end] > nums[start]) ? 1 : 0;

                    if (internal_drops + wrap_drop > 1) {
                        is_sortable = false;
                        break;
                    }
                }
                
                if (is_sortable) {
                    sum_k += k;
                }
            }
        }

        return sum_k;
    }
};