class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        int totalDays = 31 * (month - 1) + day;
        if (month > 2) {
            totalDays -= (4 * month + 23) / 10;
            if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
                totalDays += 1;
            }
        }
        return totalDays;
    }
};