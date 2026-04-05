class Solution {
public:
    bool judgeCircle(string moves) {
        int up = 0, dn = 0, l = 0, r = 0;
        
        for(int i = 0; i < moves.length(); i++){
            if(moves[i] == 'U'){
                up++;
            }else if(moves[i] == 'D'){
                dn++;
            }else if(moves[i] == 'R'){
                r++;
            }else{
                l++;
            }
        }
    return up == dn && r == l;
    }
};