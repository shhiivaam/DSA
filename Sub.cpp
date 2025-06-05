class Solution {
    public:
        long long countGoodIntegers(int n, int k) {
        int base = pow(10, (n - 1) / 2);
        vector<int>arr;
        int s=0;
    for(int i=base;i<base *10;i++){
         if(isp(i)){
          arr.push_back(i);
         }
     }
     int cnt=0;
     for(int i=0;i<arr.size();i++){
        if(arr[i]%k == 0){
           cnt++;
        }else{
            if(iS(arr[i],k)) cnt++;
        }
    } 
    return cnt;  
    }
    private:
    bool isp(int n){
        int mod=1e9+7;
        int num=n;
        int ans=0;
        while(num > 0){
            int ld=num%10;
            ans =(ans*10)%mod+ld;
            num=num/10;
        }
       if(ans != n) return 0;
       else return 1;
    }
    bool iS(int num, int k) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        unordered_set<string> seen;
        do {
            if (s[0] == '0') continue; 
            if (seen.count(s)) continue;
            seen.insert(s);
            int val = stoi(s);
            if (val % k == 0)
                return true;
        } while (next_permutation(s.begin(), s.end()));
        return false;
    }
    };
