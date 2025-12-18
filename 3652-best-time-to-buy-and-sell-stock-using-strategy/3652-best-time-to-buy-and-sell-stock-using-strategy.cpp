#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long currentProfit = 0;

        // 1. Calculate the base profit with the original strategy
        for (int i = 0; i < n; ++i) {
            currentProfit += (long long)strategy[i] * prices[i];
        }
        auto getDiffHold = [&](int i) {
            return 0LL - ((long long)strategy[i] * prices[i]);
        };

        auto getDiffSell = [&](int i) {
            return (long long)prices[i] - ((long long)strategy[i] * prices[i]);
        };

        int half = k / 2;
        long long sum1 = 0; // Gain for the first half (changing to 0)
        long long sum2 = 0; // Gain for the second half (changing to 1)

        // 2. Initialize the first window
        // First half: indices 0 to half-1
        for (int i = 0; i < half; ++i) {
            sum1 += getDiffHold(i);
        }
        // Second half: indices half to k-1
        for (int i = half; i < k; ++i) {
            sum2 += getDiffSell(i);
        }

        long long maxGain = sum1 + sum2;

        // 3. Slide the window
        // i represents the START of the new window
        for (int i = 1; i <= n - k; ++i) {
            // Remove the element that fell out of the first half (index i - 1)
            sum1 -= getDiffHold(i - 1);

            // Handle the middle element (index i + half - 1)
            // It moves from the second half (Sell) to the first half (Hold)
            int midIndex = i + half - 1;
            sum2 -= getDiffSell(midIndex);
            sum1 += getDiffHold(midIndex);

            // Add the new element entering the second half (index i + k - 1)
            sum2 += getDiffSell(i + k - 1);

            // Update max gain
            maxGain = max(maxGain, sum1 + sum2);
        }

        // 4. Return base profit + best modification (or 0 if modification hurts)
        return currentProfit + max(0LL, maxGain);
    }
};