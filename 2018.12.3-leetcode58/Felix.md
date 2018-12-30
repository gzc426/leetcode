```javascript
package leetcode.easy;
/**
 * @author Felix
 * @date 2018年11月17日下午10:52:33
   @version 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
如果不存在最后一个单词，请返回 0 。
说明：一个单词是指由字母组成，但不包含任何空格的字符串。
示例:输入: "Hello World"  输出: 5
 */
public class LengthOfLastWord {
	 public int lengthOfLastWord(String s) {
		if(s == null || s.trim().length() == 0)
			return 0;
		String[] str = s.split(" ");
		String res = str[str.length-1];
		
		return res.length();
	 }
}

```
