class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
     int total = accumulate(apple.begin(),apple.end(),0);
     sort(capacity.rbegin(),capacity.rend());
     for(int i = 0; i < (int)capacity.size(); i++){
         total -= capacity[i];
         if(total <= 0) return i + 1;
     }
    return -1;
    }
};