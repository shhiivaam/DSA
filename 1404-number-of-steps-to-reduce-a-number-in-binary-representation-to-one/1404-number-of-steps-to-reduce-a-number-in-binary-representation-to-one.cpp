class Solution {
public:
    int numSteps(string s) {
        int count = 0 , carry = 0;

        for(int i = s.size()-1 ; i > 0 ; i--){
            int bit = (s[i] - '0') + carry;
            if(bit == 1){
                carry = 1;
                count += 2;
            }
            else{
                count++; 
            }
        }
        
        return count + carry;
    }
};