```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        int index = -1;
        for (char c : s.toCharArray()) {
            // 每次从下一个位置开始找
            index = t.indexOf(c, index + 1);
            // 没找到
            if (index == -1) {
                return false;
            }
        }
        return true;
    }
}
```
