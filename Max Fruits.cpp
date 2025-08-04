class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int head = -1, tail = 0;
        int ans = 0;

        unordered_map<int, int> mp; // fruit -> count

        while (tail < n) {
            // expand window while <= 2 fruit types
            while (head + 1 < n && (mp.size() < 2 || mp.count(fruits[head + 1]) > 0)) {
                head++;
                mp[fruits[head]]++;
            }

            ans = max(ans, head - tail + 1);

            // shrink window
            if (tail > head) {
                tail++;
                head = tail - 1;
            } else {
                mp[fruits[tail]]--;
                if (mp[fruits[tail]] == 0) {
                    mp.erase(fruits[tail]);
                }
                tail++;
            }
        }
        return ans;
    }
};
