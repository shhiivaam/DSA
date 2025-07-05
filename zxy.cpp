#include <bits/stdc++.h>
using namespace std;

double mysqrt(double val) {
    if (val == 0.0) return 0.0;
    double lo = 0.0, hi = val;
    if (val < 1.0) hi = 1.0;
    for (int i = 0; i < 100; ++i) {
        double mid = (lo + hi) / 2.0;
        if (mid * mid < val)
            lo = mid;
        else
            hi = mid;
    }
    return (lo + hi) / 2.0;
}
void solve() {
    int n;
    cin >> n;
    int a, b, x, y;
    cin >> a>> b >> x >> y;
    vector<int> v(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >>v[i];
    }
    for(int i=-0;i<n;i++){
        sum += v[i];
    }
    long long dx = x - a;
    long long dy = y - b;
    long long D_squared = dx * dx + dy * dy;
    double D = mysqrt((double)D_squared);

    if (sum < D) {
        cout << "No\n";
    } else {
        if (D_squared == 0) {
            if (sum % 2 == 0) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else {
            if (sum >= D) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

