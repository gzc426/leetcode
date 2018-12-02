
58. 最后一个单词的长度 https://leetcode-cn.com/problems/length-of-last-word/

给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指由字母组成，但不包含任何空格的字符串。

示例:

输入: "Hello World"
输出: 5


class Solution {
    public int lengthOfLastWord(String s) {
        s = s.trim();
        int result = 0;
        if("".equals(s)) return result;
        if(!s.contains(" ")) return s.length();
        for(int i = s.lastIndexOf(" ")+1; i<s.length(); i++){
            result++;
        }
        return result;
    }
}
