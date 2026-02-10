class Solution {
public:
    int longestBalanced(vector<int>& nums) {
            int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, pair<int,int>> mp;
            int distinctEven = 0, distinctOdd = 0;

            for (int j = i; j < n; j++) {
                int x = nums[j];

                if (x % 2 == 0) {
                    if (mp[x].first == 0) {
                        distinctEven++;    
                    }
                    mp[x].first++;
                } else {
                    if (mp[x].second == 0) {
                        distinctOdd++;     
                    }
                    mp[x].second++;
                }

                if (distinctEven == distinctOdd) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};