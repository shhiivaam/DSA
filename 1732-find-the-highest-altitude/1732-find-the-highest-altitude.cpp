class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        int gg = 0;
        for(auto v : gain){
            maxi = max(maxi,gg);
            gg += v;
        }
        return max(gg,maxi);
    }
};