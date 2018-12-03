```java
class Solution {
    public int lengthOfLastWord(String s) {
        int res = 0;
        int i = s.length() - 1;
        for (; i >= 0 && s.charAt(i) == ' '; --i);
        for (; i >= 0 && s.charAt(i) != ' '; --i) {
            ++res;
        }
        return res;
    }
}
```
