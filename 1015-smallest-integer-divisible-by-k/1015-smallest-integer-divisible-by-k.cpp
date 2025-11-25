class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int len = 1 , num = 1;
        unordered_map<int,int>mp;
        while (mp[num] < 1) {        
            int rem = num % k;
            if (rem == 0)
                return len;
            mp[rem] = 1;             
            len++;
            num = (rem * 10 + 1) % k;  
        }
        return -1;
    }
};