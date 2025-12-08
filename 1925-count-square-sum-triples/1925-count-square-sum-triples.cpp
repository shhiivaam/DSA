class Solution {
public:
    int countTriples(int n) {
        int cnt  = 0;
        for(int i = 1; i <= n ; i++){
            for(int j =i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                   long long a = i * i;
                   long long b = j * j;
                   long long c = k * k;
                   if( a + b == c || a + c == b || c + b == a){
                        cnt += 2;
                   }
                }
            }
        }
    return cnt;
    }
};