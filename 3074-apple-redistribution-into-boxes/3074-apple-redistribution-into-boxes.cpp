class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
       int sum = accumulate(apple.begin(),apple.end(),0);
       sort(capacity.rbegin(),capacity.rend());
       int c_sum =0;
       for(int i =0;i<capacity.size();i++){
            c_sum += capacity[i];
            if(c_sum >= sum){
                return i+1;
            }
       } 
    return -1;
    }
};