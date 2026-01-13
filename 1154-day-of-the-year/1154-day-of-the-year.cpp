class Solution {
public:
    int dayOfYear(string date) {
        struct tm t = {0};
        t.tm_year = stoi(date.substr(0, 4)) - 1900; 
        t.tm_mon  = stoi(date.substr(5, 2)) - 1; 
        t.tm_mday = stoi(date.substr(8, 2)); 
        mktime(&t);
        return t.tm_yday + 1;
    }
};