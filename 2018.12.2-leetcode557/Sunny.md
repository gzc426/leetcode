```java
class Solution {
    public String reverseWords(String s) {
        if (s == null)
            return null;
        StringBuilder result = new StringBuilder(s.length());
        StringBuffer word = new StringBuffer();
        for (int i=0; i < s.length(); i++) {
            if (s.charAt(i) != ' ') {
                word.insert(0, s.charAt(i));
            }
            else {
                result.append(word);
                result.append(" ");
                word = new StringBuffer();
            }
        }
        result.append(word);
        return result.toString();
    }
}
```
