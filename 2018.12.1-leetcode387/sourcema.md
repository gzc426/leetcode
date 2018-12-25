# LeetCode 387
    class Solution {
    public int firstUniqChar(String s) {
        if (s.length() == 0 || s == null) {
            return -1;
        }
        int[] arr = new int[26];
        for (int i = 0; i < s.length(); i++) {
            arr[s.charAt(i) - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (arr[s.charAt(i)-'a']==1) {
                return i;
            }
        }
        return -1;
    }
}
