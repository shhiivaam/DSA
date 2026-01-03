class Solution {
public:
    int numOfWays(int n) {
       const int mod = 1e9 + 7;
       long long a=6,b=6;
       for(int i = 2 ; i<= n; i++){
            long long newA = (2*a + 2*b)%mod;
            long long newB = (2*a + 3*b)%mod;
            a = newA;
            b = newB;
       } 
      return (a+b)%mod; 
    }
};