#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<set<int>> cubes(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            int d;
            cin >> d;
            cubes[i].insert(d);
        }
    }
    for (int num = 1; num <= 999; num++) {
        vector<int> digits;
        int tmp = num;
        while (tmp > 0) {
            digits.push_back(tmp % 10);
            tmp /= 10;
        }
        reverse(digits.begin(), digits.end());
        if ((int)digits.size() > n) {
            cout << num - 1 << endl;
            return 0;
        }
        bool canBuild = false;
        vector<int> indices(n);
        for (int i = 0; i < n; i++) indices[i] = i;
        vector<bool> selectMask(n, false);
        for (int i = 0; i < (int)digits.size(); i++) selectMask[i] = true;
        do {
            vector<int> selectedIndices;
            for (int i = 0; i < n; i++) {
                if (selectMask[i]) selectedIndices.push_back(i);
            }
            do {
                bool ok = true;
                for (int i = 0; i < (int)digits.size(); i++) {
                    int cubeIdx = selectedIndices[i];
                    int digit = digits[i];
                    if (cubes[cubeIdx].count(digit) == 0) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    canBuild = true;
                    break;
                }
            } while (next_permutation(selectedIndices.begin(), selectedIndices.end()));
 
            if (canBuild) break;
 
        } while (prev_permutation(selectMask.begin(), selectMask.end()));
 
        if (!canBuild) {
            cout << num - 1 << endl;
            return 0;
        }
    }
    cout << 999 << endl;
    return 0;
