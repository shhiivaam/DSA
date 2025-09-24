class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string result;
        if ((numerator < 0) ^ (denominator < 0)) {
            result += "-";
        }
        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);
        result += to_string(n / d);
        long long remainder = n % d;
        if (remainder == 0) return result;
        result += ".";
        unordered_map<long long, int> remainderMap;
        while (remainder != 0) {
            if (remainderMap.find(remainder) != remainderMap.end()) {
                result.insert(remainderMap[remainder], "(");
                result += ")";
                break;
            }
            remainderMap[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / d);
            remainder %= d;
        }
        return result;
    }
};
