# LeetCode 91
    class Solution {
    public int numDecodings(String s) {
        if (s.length() == 0||s.charAt(0)=='0') {
            return 0;
        }
        return find(s,0);
    }
    private  int find(String s,int index) {
        if (index == s.length()) {
            return 1;
        }
        if (s.charAt(index) == '0') {
            return 0;
        }
        int res=0;
        res += find(s, index + 1);
      if (index + 1 < s.length() && s.charAt(index) == '1') {
            res += find(s,index+ 2);
        }
        if (index + 1 < s.length() && (s.charAt(index) == '2')&&s.charAt(index+1)<='6') {
            res += find(s,index + 2);
        }
        return res;
    }
}
