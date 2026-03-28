#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n, ' ');
        char c = 'a';
        for (int i = 0; i < n; ++i) {
            if (word[i] == ' ') {
                if (c > 'z') return ""; 
                word[i] = c;
                for (int j = i + 1; j < n; ++j) {
                    if (lcp[i][j] > 0) {
                        word[j] = c;
                    }
                }
                c++;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int expected = 0;
                if (word[i] == word[j]) {
                    expected = 1 + ((i + 1 < n && j + 1 < n) ? lcp[i + 1][j + 1] : 0);
                }
                if (lcp[i][j] != expected) {
                    return ""; 
                }
            }
        }

        return word;
    }
};