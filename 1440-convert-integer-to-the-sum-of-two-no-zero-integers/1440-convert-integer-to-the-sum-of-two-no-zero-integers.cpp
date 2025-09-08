class Solution {
    public:
    bool no(int n){
        while(n != 0){
            int ld =n%10;
            if(ld == 0) return false;
            n /=10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int>v;
        if(n==2){
            v.push_back(n/2);
            v.push_back(n/2);
        }else{
             for(int i=1;i<=n;i++){
             if(no(i) && no(n-i)){
              if(n-i + i == n)
              v.push_back(n-i);
              v.push_back(i);
              break;
             } 
         }
        } 
    return v;
    }
};