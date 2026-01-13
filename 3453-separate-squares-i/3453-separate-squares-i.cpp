class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double total = 0;
        double low = 1e18, high = -1e18;

        for (auto &s : squares) {
            double y = s[1], l = s[2];
            total += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double half = total / 2.0;

        auto areaBelow = [&](double Y) {
            double area = 0;
            for (auto &s : squares) {
                double y = s[1], l = s[2];
                if (Y <= y) continue;
                if (Y >= y + l) area += l * l;
                else area += l * (Y - y);
            }
            return area;
        };

        for (int i = 0; i < 80; i++) {  
            double mid = (low + high) / 2;
            if (areaBelow(mid) < half)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};
