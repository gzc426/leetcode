# leetcode 557
    class Solution {
    public String reverseWords(String s) {
        if (s == null || s.length() == 0) {
            return s;
        }
        int start=s.charAt(0)!=' '?0:1;
        int end=-1;
        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] == ' ') {
                end=i-1;
                change(chars, start, end);
                start=i+1;
            }
        }
        change(chars, start, chars.length - 1);
        return String.valueOf(chars);
    }
    private  void change(char[] chars, int start, int end) {
        while (start < end) {
            char temp = chars[start];
            chars[start] = chars[end];
            chars[end]=temp;
            start++;
            end--;
        }
    }
}
