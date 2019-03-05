# leetcode 17
    class Solution {
    
    static String[] letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    public static List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        if (digits == null || digits.length() == 0) {
            return res;
        }
        dfs(digits, res, 0, digits.length(), "");
        return res;
    }

    private static void dfs(String digits, List<String> res, int index, int length, String ret) {
        if (index >= length) {
            res.add(ret);
            return;
        }
        int digit = digits.charAt(index) - '0';
        for (int i = 0; i <letters[digit].length(); i++) {
            ret += letters[digit].charAt(i);
            dfs(digits, res, index + 1, length, ret);
            ret=ret.substring(0, ret.length() - 1);
        }
    }
}
