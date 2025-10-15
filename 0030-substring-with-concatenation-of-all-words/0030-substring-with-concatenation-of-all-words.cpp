#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty() || s.empty()) return res;

        int word_len = words[0].size();
        int total_words = words.size();
        int total_len = word_len * total_words;
        if (s.size() < total_len) return res;

        unordered_map<string, int> word_count;
        for (auto &w : words) word_count[w]++;

        for (int i = 0; i < word_len; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> window_count;

            for (int right = i; right + word_len <= s.size(); right += word_len) {
                string word = s.substr(right, word_len);

                if (word_count.count(word)) {
                    window_count[word]++;
                    count++;

                    while (window_count[word] > word_count[word]) {
                        string left_word = s.substr(left, word_len);
                        window_count[left_word]--;
                        left += word_len;
                        count--;
                    }

                    if (count == total_words)
                        res.push_back(left);
                } else {
                    window_count.clear();
                    count = 0;
                    left = right + word_len;
                }
            }
        }
        return res;
    }
};
