class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        int total = accumulate(card.begin(), card.end(), 0);
        if (n == k) return total;

        int window = n - k; // number of cards to leave
        int curr = accumulate(card.begin(), card.begin() + window, 0);
        int min_sum = curr;

        for (int i = window; i < n; i++) {
            curr += card[i] - card[i - window];
            min_sum = min(min_sum, curr);
        }

        return total - min_sum;
    }    
};
