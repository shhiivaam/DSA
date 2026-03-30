class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if (s1 == s2)  return true;

        // Agr ham sirf tab hi swap kr skte h
        // jab j - i even ho

        // 0 1 2 3 4 5
        // 0 -> 2
        // 0 -> 4
        // 1 -> 3
        // 1 -> 5
        // 2 -> 4
        // 3 -> 5
        // we can swap all the i -> j , where diff is -> 2, formally for each i
        // i += 2, we can swap.

        // string a = "", a_ = "";
        // string b = "", b_ = "";

        // for (int i = 0; i < n; i += 2) {
        //     a += s1[i];
        //     a_ += s2[i];
        // }
        // for (int i = 1; i < n; i += 2) {
        //     b += s1[i];
        //     b_ += s2[i];
        // }
        // sort(a.begin(), a.end());
        // sort(a_.begin(), a_.end());
        // sort(b.begin(), b.end());
        // sort(b_.begin(), b_.end());
        // return a == a_ && b == b_;
        int n = s1.size();
        
        vector<int> even1(26, 0), odd1(26, 0);
        vector<int> even2(26, 0), odd2(26, 0);

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                even1[s1[i] - 'a']++;
                even2[s2[i] - 'a']++;
            } else {
                odd1[s1[i] - 'a']++;
                odd2[s2[i] - 'a']++;
            }
        }

        return (even1 == even2) && (odd1 == odd2);
    }
};