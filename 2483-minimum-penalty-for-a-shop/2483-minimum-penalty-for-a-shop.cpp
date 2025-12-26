class Solution {
public:
    int bestClosingTime(string customers) {
        int totalY = 0;
        for (char c : customers) {
            if (c == 'Y') totalY++;
        }
        int penalty = totalY;
        int minPenalty = penalty;
        int answer = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y')
                penalty--;
            else
                penalty++;

            if (penalty < minPenalty) {
                minPenalty = penalty;
                answer = i + 1;
            }
        }
        return answer;
    }
};
