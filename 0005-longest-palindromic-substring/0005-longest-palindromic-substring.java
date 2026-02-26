class Solution {

    void solve(String str , int i , int j , String[] ans){

        while(i >= 0 && j < str.length() && str.charAt(i) == str.charAt(j)){
            int currLen = j - i + 1;

            if(currLen > ans[0].length()){
                ans[0] = str.substring(i , j + 1);
            }
            i--;
            j++;
        }
    }

    public String longestPalindrome(String s) {
        String[] ans = new String[]{""};

        for(int i = 0 ; i < s.length() ; i++){
            solve(s , i , i  , ans);
            solve(s , i , i+1  , ans);
        }

        return ans[0];
    }
}