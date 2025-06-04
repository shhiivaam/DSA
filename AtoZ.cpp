#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        long long int n = s.size();
        long long int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        int flag1 = -1, flag2 = -1;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            // cout << i << nl;
            if (flag2 != -1)
            {
                if (('a' <= s[i] && s[i] <= 'z'))
                {
                    cnt3++;
                }
                else
                {
                    // cout << i << " " << cnt1 << " " << cnt2 << " " << cnt3 << '\n';
                    ans += (cnt1 * cnt3);
                    cnt1 = cnt2 = cnt3 = 0;
                    i = flag2;
                    flag1 = flag2 = -1;
                }
            }
            else if (flag1 != -1)
            {
                if (('a' <= s[i] && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9'))
                {
                    cnt2++;
                }
                else
                {
                    if (s[i] == '\\' && cnt2) //second pointer fixed at this index
                    {
                        flag2 = i;
                    }
                    else
                    {
                        i = flag1;
                        flag1 = -1;
                        cnt1 = cnt2 = 0;
                    }
                }
            }
            else
            {
                if ('a' <= s[i] && s[i] <= 'z')
                {
                    cnt1++;
                }
                else
                {
                    if (cnt1 == 0 || (s[i] == ':' || ('0' <= s[i] && s[i] <= '9')))
                    {
                        continue;
                    }
                    else if (s[i] == '/') //first pointer fixed at this index
                    {
                        flag1 = i;
                    }
                    else
                    {
                        cnt1 = 0;
                    }
                }
            }
        }

        if (flag2 != -1 && cnt3)
        {
            // cout << cnt1 << " " << cnt2 << " " << cnt3 << '\n';
            ans += (cnt1 * cnt3);
        }

        cout << ans << '\n';
    }

    return 0;
}
