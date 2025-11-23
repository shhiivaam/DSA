class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int total = 0;
        vector<int> rem1;
        vector<int> rem2;
        for (int x : nums) {
            total = total + x;
            if (x % 3 == 1) {
                rem1.push_back(x);
            }
            else if (x % 3 == 2) {
                rem2.push_back(x);
            }
        }
        sort(rem1.begin(), rem1.end());
        sort(rem2.begin(), rem2.end());
        if (total % 3 == 0) {
            return total;
        }
        int answer = 0;
        if (total % 3 == 1) {
            int option1 = INT_MAX;
            int option2 = INT_MAX;
            if (rem1.size() >= 1) {
                option1 = rem1[0];
            }
            if (rem2.size() >= 2) {
                option2 = rem2[0] + rem2[1];
            }
            int remove_value = min(option1, option2);
            if (remove_value == INT_MAX) {
                return 0;
            }
            answer = total - remove_value;
        }
        else { 
            int option1 = INT_MAX;
            int option2 = INT_MAX;

            if (rem2.size() >= 1) {
                option1 = rem2[0];
            }
            if (rem1.size() >= 2) {
                option2 = rem1[0] + rem1[1];
            }
            int remove_value = min(option1, option2);

            if (remove_value == INT_MAX) {
                return 0;
            }
            answer = total - remove_value;
        }
        return answer;
    }
};
