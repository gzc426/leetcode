```java
class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> res = new ArrayList<>();
        for (String word : words) {
            if (match(word, pattern)) {
                res.add(word);
            }
        }
        return res;
    }

    private boolean match(String s, String p) {
        int[] index1 = new int[26];
        int[] index2 = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            int i1 = s.charAt(i) - 'a';
            int i2 = p.charAt(i) - 'a';
            if (index1[i1] != index2[i2]) {
                return false;
            }
            index1[i1] = index2[i2] = i + 1;
        }
        return true;
    }
}
```
