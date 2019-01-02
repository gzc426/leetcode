class Solution {
    public boolean isSubsequence(String s, String t) {
        char[] tempS = s.toCharArray();
        char[] tempT = t.toCharArray();
        int s_l = tempS.length;
        int t_l = tempT.length;

        if (s_l > t_l) {
            return false;
        } else if (s_l == 0) {
            return true;
        }
        int i = 0;
        for (int j = 0; j < t_l; j++) {
            if (tempS[i] == tempT[j]) {
                if (i == s_l - 1) {
                    return true;
                } else {
                    i++;
                }
            }
        }
        return false;
    }
}
