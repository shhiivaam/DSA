class Solution {
public:
    bool isValidCode(string &s) {
        if (s.empty()) return false;
        for (char c : s) {
            if (!(isalnum(c) || c == '_')) {
                return false;
            }
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        unordered_map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<int, string>> validCoupons;

        for (int i = 0; i < code.size(); i++) {
            if (!isActive[i]) continue;

            if (priority.find(businessLine[i]) == priority.end())
                continue;

            if (!isValidCode(code[i])) continue;

            validCoupons.push_back({
                priority[businessLine[i]],
                code[i]
            });
        }

        sort(validCoupons.begin(), validCoupons.end(),
             [](auto &a, auto &b) {
                 if (a.first == b.first)
                     return a.second < b.second;
                 return a.first < b.first;
             });

        vector<string> result;
        for (auto &p : validCoupons) {
            result.push_back(p.second);
        }
        return result;
    }
};
