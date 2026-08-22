class Solution {
public:
    bool checkDivisibility(int n) {
       int sum = 0;
       long long prod = 1;
       int num = n;

       while(num > 0){
         int ld = num % 10;
         sum += ld;
         prod *= ld;
         num /= 10;
       } 
       prod += sum;

       if(n % prod == 0) return true;
       return false;
    }
};