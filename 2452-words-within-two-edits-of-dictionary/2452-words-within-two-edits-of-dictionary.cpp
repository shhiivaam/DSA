class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> result;
        for (const string& queryWord : queries) {
            for (const string& dictWord : dictionary) {
                int differences = 0;
                for (int i = 0; i < queryWord.length(); ++i) {
                    if (queryWord[i] != dictWord[i]) {
                        differences++;
                    }
                }
                if (differences <= 2) {
                    result.push_back(queryWord);
                    break;
                }
            }
        }

        return result;
    }
};