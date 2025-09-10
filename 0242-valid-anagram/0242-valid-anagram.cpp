class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char, int> freq;

        // Count frequency in s
        for(char c : s) {
            freq[c]++;
        }

        // Reduce frequency using t
        for(char c : t) {
            freq[c]--;
            if(freq[c] < 0) return false; // extra char in t
        }

        return true;  // all counts matched
    }
};