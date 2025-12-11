class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, set<int>> row, col;
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            row[x].insert(y);
            col[y].insert(x);
        }
        int count = 0;
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            bool left = (*row[x].begin() < y);
            bool right = (*row[x].rbegin() > y);
            bool up = (*col[y].begin() < x);
            bool down = (*col[y].rbegin() > x);
            if (left && right && up && down) {
                count++;
            }
        }
        return count;
    }
};