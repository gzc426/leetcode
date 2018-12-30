```java
class Solution {
    public int lengthOfLastWord(String s) {
        if (s == null) return 0;
        int i = s.lastIndexOf(" ");
        if (i < 0) return s.length();
        if (i == (s.length() - 1) && s.length() > 1) {
            s = s.substring(0, i);
            return lengthOfLastWord(s);
        }
        return s.substring(i+1, s.length()).length();
    }
}
```
