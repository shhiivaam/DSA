class Solution {
public:
    int numberOfWays(string corridor) {
        vector<int> seat_indices;
        for (int i = 0; i < corridor.length(); i++) {
            if (corridor[i] == 'S') {
                seat_indices.push_back(i);
            }
        }
        if (seat_indices.size() == 0 || seat_indices.size() % 2 != 0) {
            return 0;
        }
        long long ans = 1;
        long long MOD = 1e9 + 7;
        for (int i = 2; i < seat_indices.size(); i += 2) {
            int prev_seat_index = seat_indices[i - 1];
            int curr_seat_index = seat_indices[i];
            long long ways_for_this_gap = curr_seat_index - prev_seat_index;
            ans = (ans * ways_for_this_gap) % MOD;
        }
        return (int)ans;
    }
};