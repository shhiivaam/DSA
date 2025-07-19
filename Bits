#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    const int MAX_BITS = 60;
    long long val = 0;

    while (q--) {
        int st;
        cin >> st;

        if (st >= 1 && st <= 4) {
            int i;
            cin >> i;
            if (st == 1) {
                // test(i)
                cout << ((val >> i) & 1) << '\n';
            } else if (st == 2) {
                // set(i)
                val |= (1LL << i);
            } else if (st == 3) {
                // clear(i)
                val &= ~(1LL << i);
            } else if (st == 4) {
                // flip(i)
                val ^= (1LL << i);
            }
        } else if (st == 5) {
            // all
            cout << ((val == (1LL << MAX_BITS) - 1) ? 1 : 0) << '\n';
        } else if (st == 6) {
            // any
            cout << (val != 0 ? 1 : 0) << '\n';
        } else if (st == 7) {
            // none
            cout << (val == 0 ? 1 : 0) << '\n';
        } else if (st == 8) {
            // count
            cout << __builtin_popcountll(val) << '\n';
        } else if (st == 9) {
            // val
            cout << val << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
