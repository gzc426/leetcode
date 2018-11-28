```java
public class Solution {
    public String reverseWords(String s) {
        StringBuilder sb = new StringBuilder();
        char[] chars = s.toCharArray();
        int i = chars.length - 1;
        while (i >= 0) {
            while (i >= 0 && chars[i] == ' ') {
                --i;
            }
            if (i >= 0) {
                int j = i;
                while (i >= 0 && chars[i] != ' ') {
                    --i;
                }
                sb.append(chars, i + 1, j - i).append(' ');
                --i;
            }
        }
        if (sb.length() > 0) {
            sb.setLength(sb.length() - 1);
        }
        return sb.toString();
    }
}
```
