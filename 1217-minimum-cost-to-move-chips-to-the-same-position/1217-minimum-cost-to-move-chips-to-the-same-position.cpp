class Solution {
public:
    int minCostToMoveChips(vector<int>& pos) {
        int even = 0;
        int odd = 0;
        int n = pos.size();
        for(int i = 0; i < n; i++){
            if(pos[i] % 2 == 0) even++;
            else
            odd++;
        }
    return min(even,odd);
    }
};