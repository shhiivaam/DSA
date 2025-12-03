#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
    struct Segment {
        long long dx, dy;
        long long val;
        int u, v;

        bool operator<(const Segment& other) const {
            if (dx != other.dx) return dx < other.dx;
            if (dy != other.dy) return dy < other.dy;
            return val < other.val;
        }
    };

    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

public:
    long long countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4) return 0;

        vector<Segment> segments;
        segments.reserve(n * (n - 1) / 2);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long dx = points[j][0] - points[i][0];
                long long dy = points[j][1] - points[i][1];
                
                long long g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;
                
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }
                
                long long val = (long long)points[i][0] * dy - (long long)points[i][1] * dx;
                segments.push_back({dx, dy, val, i, j});
            }
        }

        sort(segments.begin(), segments.end());

        long long parallelPairsCount = 0;
        int m = segments.size();
        int i = 0;

        while (i < m) {
            int j = i;
            while (j < m && segments[j].dx == segments[i].dx && segments[j].dy == segments[i].dy) {
                j++;
            }
            
            map<long long, int> waysPerLine;
            int k = i;
            while (k < j) {
                int l = k;
                long long currentVal = segments[k].val;
                
                vector<int> distinctPoints;
                while (l < j && segments[l].val == currentVal) {
                    distinctPoints.push_back(segments[l].u);
                    distinctPoints.push_back(segments[l].v);
                    l++;
                }
                
                sort(distinctPoints.begin(), distinctPoints.end());
                int uniqueCount = unique(distinctPoints.begin(), distinctPoints.end()) - distinctPoints.begin();
                
                if (uniqueCount >= 2) {
                    waysPerLine[currentVal] = uniqueCount * (uniqueCount - 1) / 2;
                }
                k = l;
            }
            
            long long sumWays = 0;
            long long sumSqWays = 0;
            
            for (auto const& [val, count] : waysPerLine) {
                sumWays += count;
                sumSqWays += (long long)count * count;
            }
            
            parallelPairsCount += (sumWays * sumWays - sumSqWays) / 2;
            i = j;
        }

        map<pair<long long, long long>, map<pair<long long, long long>, int>> midPoints;
        
        for (int a = 0; a < n; ++a) {
            for (int b = a + 1; b < n; ++b) {
                long long mx = (long long)points[a][0] + points[b][0];
                long long my = (long long)points[a][1] + points[b][1];
                
                long long dx = points[b][0] - points[a][0];
                long long dy = points[b][1] - points[a][1];
                long long g = gcd(abs(dx), abs(dy));
                dx /= g; dy /= g;
                if (dx < 0 || (dx == 0 && dy < 0)) { dx = -dx; dy = -dy; }
                
                midPoints[{mx, my}][{dx, dy}]++;
            }
        }
        
        long long parallelogramCount = 0;
        for (auto& entry : midPoints) {
            auto& slopeMap = entry.second;
            long long totalDiagonals = 0;
            long long degeneratePairs = 0;
            
            for (auto& s : slopeMap) {
                long long cnt = s.second;
                totalDiagonals += cnt;
                degeneratePairs += cnt * (cnt - 1) / 2;
            }
            
            long long totalPairs = totalDiagonals * (totalDiagonals - 1) / 2;
            parallelogramCount += (totalPairs - degeneratePairs);
        }

        return parallelPairsCount - parallelogramCount;
    }
};