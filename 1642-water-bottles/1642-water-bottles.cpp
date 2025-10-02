class Solution {
public:
    int numWaterBottles(int b, int e) {
        int ans = b;
        while (b >= e) { 
            int newBottles = b / e;  
            ans += newBottles;       
            b = newBottles + (b % e); 
        }
        return ans;
    }
};