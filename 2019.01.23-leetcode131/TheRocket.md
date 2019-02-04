```java
class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        List<String> list = new ArrayList<>();
        dfs(s, res, list);
        return res;
    }

    private void dfs(String s, List<List<String>> res, List<String> list) {
        if (s.length() == 0) {
            res.add(new ArrayList<>(list));
            return;
        }
        for (int i = 1; i <= s.length(); ++i) {
            String sub = s.substring(0, i);
            if (isPalindrome(sub)) {
                list.add(sub);
                dfs(s.substring(i), res, list);
                list.remove(list.size() - 1);
            }
        }
    }

    private boolean isPalindrome(String s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--)) {
                return false;
            }
        }
        return true;
    }
}
```
