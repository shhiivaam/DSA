class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 0;

        int current_run = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && s[i] == s[i - 1]) {
                current_run++;
            } else {
                current_run = 1;
            }
            ans = max(ans, current_run);
        }

        auto solve_two = [&](char c1, char c2, char forbidden) {
            int max_len = 0;
            int diff = 0;
            unordered_map<int, int> seen;
            seen[0] = -1;

            for (int i = 0; i < n; ++i) {
                if (s[i] == forbidden) {
                    seen.clear();
                    seen[0] = i;
                    diff = 0;
                } else {
                    if (s[i] == c1) diff++;
                    else if (s[i] == c2) diff--;

                    if (seen.count(diff)) {
                        max_len = max(max_len, i - seen[diff]);
                    } else {
                        seen[diff] = i;
                    }
                }
            }
            return max_len;
        };

        ans = max(ans, solve_two('a', 'b', 'c'));
        ans = max(ans, solve_two('b', 'c', 'a'));
        ans = max(ans, solve_two('a', 'c', 'b'));

        map<pair<int, int>, int> seen_three;
        seen_three[{0, 0}] = -1;
        int ca = 0, cb = 0, cc = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') ca++;
            else if (s[i] == 'b') cb++;
            else if (s[i] == 'c') cc++;

            pair<int, int> key = {ca - cb, cb - cc};
            
            if (seen_three.count(key)) {
                ans = max(ans, i - seen_three[key]);
            } else {
                seen_three[key] = i;
            }
        }

        return ans;
    }
};