##### 题目
```
给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指由字母组成，但不包含任何空格的字符串。

示例:

输入: "Hello World"
输出: 5
```
##### 代码
```
class Solution {
    public int lengthOfLastWord(String s) {
        String str=s.trim();
        String[] strArray=s.split(" ");
        String lastStr=strArray[strArray.length-1];
        return lastStr.trim().length();
    }
}
```
> 要删除掉字符串中前后的空格
##### 代码2

```
class Solution {
    public int lengthOfLastWord(String s) {
        String str=s.trim();
        if (str==null) {
            return 0;
        }
        int count=0,i=str.length()-1;
        while(i>=0){
            if (str.charAt(i)!=' ') {
                count++;
                i--;
            }else{
                break;
            }
        }
        return count;
    }
}
```
