>给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
>如果不存在最后一个单词，请返回 0 。  
>说明：一个单词是指由字母组成，但不包含任何空格的字符串。

```
public static int lengthOfLastWord(String str){  
  String trim = str.trim();
  if (str.matches("[a-zA-Z ]*") && !trim.isEmpty()) {
      int index = trim.lastIndexOf(' ');
      return index < 0 ? trim.length() : trim.length() - index - 1;
  }
  return 0;
}
