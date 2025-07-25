#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string camel, snake = "";
    cin >> camel;
    snake += tolower(camel[0]);
    for (int i = 1; i < camel.length(); i++)
    {
        if ('a' <= camel[i] && camel[i] <= 'z')
            snake += camel[i];
        else
            snake += '_', snake += tolower(camel[i]);
    }
    cout << snake << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t = 1; // number of test cases
    cin >> _t;
    while (_t--)
        solve();
}
