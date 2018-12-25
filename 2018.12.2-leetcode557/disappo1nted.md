class Solution {
    public String reverseWords(String s) {
        int prev = 0;
        char[] cArr = s.toCharArray();
        for (int i = 0; i < cArr.length; i++) {
            if (cArr[i] == ' ') {
                reverse(cArr, prev, i - 1);
                prev = i + 1;
            }
        }
        reverse(cArr, prev, cArr.length - 1);
        return new String(cArr);
    }

    private void reverse(char[] cArr, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            char temp = cArr[i];
            cArr[i] = cArr[j];
            cArr[j] = temp;
        }
    }
}
