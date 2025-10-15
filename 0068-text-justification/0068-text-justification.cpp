#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0;
        while (i < n) {
            int lineLen = words[i].size();
            int j = i + 1;
            while (j < n && lineLen + 1 + words[j].size() <= maxWidth) {
                lineLen += 1 + words[j].size();
                j++;
            }
            int numWords = j - i;
            int totalChars = 0;
            for (int k = i; k < j; ++k) totalChars += words[k].size();

            int totalSpaces = maxWidth - totalChars;
            string line;
            if (j == n || numWords == 1) {
                for (int k = i; k < j; ++k) {
                    if (k > i) line += " ";
                    line += words[k];
                }
                line += string(maxWidth - line.size(), ' ');
            } else {
                int spacePerGap = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);

                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) {
                        int spaces = spacePerGap + (k - i < extraSpaces ? 1 : 0);
                        line += string(spaces, ' ');
                    }
                }
            }
            res.push_back(line);
            i = j;
        }
        return res;
    }
};
