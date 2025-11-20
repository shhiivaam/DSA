class Solution {
    public int intersectionSizeTwo(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> 
            a[1] == b[1] ? b[0] - a[0] : a[1] - b[1]
        );

        int a = -1, b = -1, count = 0;

        for (int[] in : intervals) {
            int s = in[0], e = in[1];

            boolean hasA = a >= s;
            boolean hasB = b >= s;

            if (hasA && hasB) continue;
            else if (hasA) {
                count++;
                b = a;
                a = e;
            } else {
                count += 2;
                b = e - 1;
                a = e;
            }
        }
        return count;
    }
}
