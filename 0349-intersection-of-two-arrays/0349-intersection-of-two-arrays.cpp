class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    vector<bool>vis(1001,false);
    for(int i = 0; i < nums1.size(); i++){
            vis[nums1[i]] = true;
     }
     for(int i =0;i < nums2.size(); i++){
        if(vis[nums2[i]] == true){
            ans.push_back(nums2[i]);
            vis[nums2[i]] = false;
        }
     }
    return ans;
    }
};