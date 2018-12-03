##### 题目
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 

注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
##### 代码

```
public class Solution {
    public String reverseWords(String s) {
        
        if(s == null){ return null;}
        
        String[] strChar=s.split(" ");
        int size=strChar.length;
        //reverse every vocabulary
        String reverse="";
        for (int i=0; i<size; ++i) { 
            strChar[i] = new StringBuilder(strChar[i]).reverse().toString();
        }
        //linking every vocabulary
        StringBuilder result = new StringBuilder();
        for (String st : strChar) {
            result.append(st + " ");
        }
        return result.toString().trim();
    }
}
```
