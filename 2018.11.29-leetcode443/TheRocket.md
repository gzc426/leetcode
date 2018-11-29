```java
class Solution {
    public int compress(char[] chars) {
        int n = 0;
        int i = 0;
        while (i < chars.length){
            chars[n++] = chars[i++];
            int cnt = 1;
            while (i < chars.length && chars[i] == chars[i - 1]) {
                ++i;
                ++cnt;
            }
            if (cnt > 1) {
                for (char c : Integer.toString(cnt).toCharArray()) {
                    chars[n++] = c;
                }
            }
        }
        return n;
    }
}
```
