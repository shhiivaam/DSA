class Solution {
public:
    int mirrorDistance(int n) {
        int num = n;
        long long rvdt_ = 0;
        while(num){
            int ld = num % 10;
            rvdt_ = (rvdt_ * 10) + ld;
            num /= 10;
        }
    return abs(rvdt_ - n);
    }
};