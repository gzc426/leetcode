# LeetCode 58
    class Solution {
    public int lengthOfLastWord(String s) {
       if (s == null || s.length() == 0) {
            return 0;
        }
        String str = s.trim();
        int length=0;
        for (int i=str.length()-1;i>=0;i--) {
            if (str.charAt(i) != ' ') {
                length++;
            } else {
                break;
            }
        }
        return length;
    }
}
