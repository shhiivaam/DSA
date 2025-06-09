#include <bits/stdc++.h>
using namespace std;

bool canPartition(const vector<int>& a, int target) {
    long long currSum = 0;
    for (int num : a) {
        currSum += num;
        if (currSum > target)
            return false;
        if (currSum == target)
            currSum = 0;
    }
    return currSum == 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for (int& x : a) {
        cin >> x;
        sum += x;
    }

    int maxGCD = 1;
    for (int i = 1; i * i <= sum; ++i) {
        if (sum % i == 0) {
            // Try partition with GCD = i
            if (canPartition(a, i)) maxGCD = max(maxGCD, i);
            // Try partition with GCD = sum / i
            if (canPartition(a, sum / i)) maxGCD = max(maxGCD, (int)(sum / i));
        }
    }

    cout << maxGCD << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
