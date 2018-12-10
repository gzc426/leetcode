```java
class Solution {
    public int firstUniqChar(String s) {
        if (s == null || "".equals(s))
            return -1;
        Map<Character, Integer> map = new LinkedHashMap<>(s.length());
        for (int i=0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (map.containsKey(c)) {
                map.put(c, -1);
            } else {
                map.put(c, i);
            }
        }
        for (int value : map.values()) {
            if (value != -1) {
                return value;
            }
        }
        return -1;
    }
}
```
