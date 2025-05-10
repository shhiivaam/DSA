#include <bits/stdc++.h>
using namespace std;
int occur(string &s, int l, int e, char ch) {
    if (l > e) 
        return 0;
    cout << s[l] << " ";
    if (s[l] == ch) {
        return 1 + occur(s, l + 1, e, ch);
    }
    return occur(s, l + 1, e, ch);
}

int main() {
   string s="abaa";
   char ch ='g';
   cout<<occur(s,0,3,ch)<<endl;
   cout<<s;
}
