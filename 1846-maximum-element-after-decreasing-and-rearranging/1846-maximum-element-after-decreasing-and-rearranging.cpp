class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // int maxi = 0;
        // for (int i = 0; i < arr.size(); i++) {
        //     maxi = max(arr[i], maxi);
        // }
        // if (maxi >= arr.size())
        //     return arr.size();
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        int maxi = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (abs(arr[i] - arr[i - 1]) > 1) {
                arr[i] = arr[i - 1] + 1;
            }
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }
};