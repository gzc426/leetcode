```java
class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        if (digits == null || digits.length() == 0) {
            return res;
        }
        res.add("");
        String[] dict = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (char c : digits.toCharArray()) {
            List<String> tmp = new ArrayList<>();
            String s = dict[c - '2'];
            for (String prefix : res) {
                for (char cur : s.toCharArray()) {
                    tmp.add(prefix + cur);
                }
            }
            res = tmp;
        }
        return res;
    }
}
```
