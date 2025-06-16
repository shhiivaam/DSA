#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
bool is_sortable(int n, int k, const std::vector<int>& p) {
    for (int i = 0; i < n; ++i) {
        if (((p[i] - 1) % k) != (i % k)) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> p(n);
    std::vector<int> bad_indices;

    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        if (((p[i] - 1) % k) != (i % k)) {
            bad_indices.push_back(i);
        }
    }

    if (bad_indices.empty()) {
        std::cout << 0 << std::endl;
    } else if (bad_indices.size() == 2) {
      int idx1 = bad_indices[0];
        int idx2 = bad_indices[1];

        // Simulate the swap
        std::swap(p[idx1], p[idx2]);

        // Check if both positions are now good
        bool fixed1 = (((p[idx1] - 1) % k) == (idx1 % k));
        bool fixed2 = (((p[idx2] - 1) % k) == (idx2 % k));

        if (fixed1 && fixed2) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }
    } else {
        std::cout << -1 << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
