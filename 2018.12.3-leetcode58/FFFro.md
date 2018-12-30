class Solution {
    public int lengthOfLastWord(String s) {
        String[] s1 = s.split(" ");
        if (s1.length == 0)
            return 0;
        return s1[s1.length-1].length();
    }
}
