class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        vector<int> vec;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                vec.push_back(grid[i][j]);
            }
        }
        sort(vec.begin() , vec.end());
        int l=0 , r=vec.size()-1 ,cnt=0;
        while(l<=r){
            int mid = (l+r)/2;
            if(vec[mid] >= 0){
                r=mid-1;
            }else{
                cnt = max(cnt , mid+1);
                l=mid+1;
            }
        }
        return cnt;
    }
};