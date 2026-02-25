class Solution {
    public int[] sortByBits(int[] arr) {

        Integer[] temp = Arrays.stream(arr).boxed().toArray(Integer[]::new);

        Arrays.sort(temp, (a, b) -> {
            int x = Integer.bitCount(a);
            int y = Integer.bitCount(b);
            if (x == y)
                return a - b;
            return x - y;
        });

        for (int i = 0; i < arr.length; i++)
            arr[i] = temp[i];

        return arr;
    }
}