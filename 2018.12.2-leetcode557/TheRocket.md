```java
class Solution {
    public String reverseWords(String s) {
        char[] cs = s.toCharArray();
        int i = 0;
        while (i < cs.length) {
            int begin = i;
            while (i < cs.length && cs[i] != ' ') {
                ++i;
            }
            reverse(cs, begin, i - 1);
            ++i;
        }
        return new String(cs);
    }

    private void swap(char[] cs, int i, int j) {
        char tmp = cs[i];
        cs[i] = cs[j];
        cs[j] = tmp;
    }

    private void reverse(char[] cs, int i, int j) {
        while (i < j) {
            swap(cs, i++, j--);
        }
    }
}
```
