import java.util.*;

class Solution {

    private void reverse(List<Long> arr) {
        int l = 0, h = arr.size() - 1;

        while (l < h) {
            Long temp = arr.get(l);
            arr.set(l, arr.get(h));
            arr.set(h, temp);
            l++;
            h--;
        }
    }

    public List<Long> mergeAdjacent(int[] arr) {
        Stack<Long> stk = new Stack<>();
        List<Long> ans = new ArrayList<>();

        for (int i = 0; i < arr.length; i++) {
            long curr = arr[i];

            while (!stk.isEmpty() && stk.peek().equals(curr))
                curr = 2 * stk.pop();

            stk.push(curr);
        }

        while (!stk.isEmpty())
            ans.add(stk.pop());

        reverse(ans);
        return ans;
    }
}
