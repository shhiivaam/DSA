class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int dist = 0;

        for (int i = 0; i < points.size() - 1; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[i + 1][0];
            int y2 = points[i + 1][1];
            dist += max(abs(x2 - x1), abs(y2 - y1));
        }
        return dist;
    }
};
