###给定一个字符串，逐个翻转字符串中的每个单词。
先整体利用Java语法，翻转整个字符，再一一翻转单词
```java
public class Solution {
    public String reverseWords(String s) {
        int index = 0,n = s.length();
        StringBuilder sb = new StringBuilder(s).reverse();//翻转整个字符串
        for(int i = 0;i < n;i++){
            if(sb.charAt(i) != ' '){//如果遍历到的字符不是空格,
                if(index != 0){//不是第一个单词
                     sb.setCharAt(index, ' ');//加空格
                     index++;//非空字符
                }
                int j = i;//从当前遍历到字符开始
                while(j < n && sb.charAt(j) != ' '){
                    sb.setCharAt(index,sb.charAt(j));//把该单词逐字复制到标记位置
                    index++;
                    j++;
                }
                String t = new StringBuilder(sb.substring(index - (j - i),index)).reverse().toString();//将该单词翻转
                sb.replace(index - (j - i),index,t);//将翻转好的单词复制进去
                i = j;//将标记移动到该单词结束
                   
            }
        }
        sb.setLength(index);//防范空格情况
        return sb.toString();
```
大神解法：
```java
public class Solution {
    public String reverseWords(String s) {
        String[] words = s.trim().split(" +");
        Collections.reverse(Arrays.asList(words));
        return String.join(" ", words);
    }
}
```
把字符串切割为字符串数组，翻转，在单词间隔加入空格
