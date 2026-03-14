class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i : nums)   mp[i]++;
        for(int i : nums)   if((i & 1) == 0 && mp[i] == 1)    return i;
        return -1;
    }
};