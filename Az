class Solution {
public:
    string generateTag(string caption) {
       string tag = "#";
        string word;
        stringstream ss(caption);
        bool first = true;
        while (ss >> word) {
            string clean = "";
            for (char ch : word) {
                if (isalpha(ch)) clean += ch;
            }
            if (clean.empty()) continue;
            if (first) {
                for (char &c : clean) c = tolower(c);
                tag += clean;
                first = false;
            } else {
                tag += toupper(clean[0]);
                for (int i = 1; i < clean.size(); i++) {
                    tag += tolower(clean[i]);
                }
            }
            if (tag.size() >= 100) {
                tag = tag.substr(0, 100);
                break;
            }
        }
        return tag;
    }
};
