```java
class Solution {
    public List<Integer> partitionLabels(String S) {
        char[] cs = S.toCharArray();
        // 字符最后一次出现的位置
        int[] last = new int[26];
        for (int i = 0; i < cs.length; ++i) {
            last[cs[i] - 'a'] = i;
        }
        List<Integer> res = new ArrayList<>();
        int start = 0;  // 区间起始位置
        int end = 0;    // 区间结束位置
        for (int i = 0; i < cs.length; ++i) {
            end = Math.max(end, last[cs[i] - 'a']);
            if (i == end) {
                res.add(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
}
```
