class Solution {
    public long minimumSteps(String s) {
        long  ans = 0 ;
        int cnt = 0 ;

        for (int i = 0; i < s.length(); i++)
            if (s.charAt(i) == '1')
                cnt++;
            else
                ans += cnt;

        return ans;
    }
}