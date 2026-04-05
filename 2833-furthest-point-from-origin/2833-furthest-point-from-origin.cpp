class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0, r = 0;
        for(int i = 0; i < moves.length(); i++){
            if(moves[i] == 'L') l++;
            else if(moves[i] == 'R') r++;
        }
        int pv = moves.length() - (l + r);
        if( l > r) return (l + pv) -  r;
        return (r + pv) - l;
    }
};