```java
class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();
        if (s == null || s.length() < 4) {
            return res;
        }
        dfs(s, res, new StringBuilder(), 0, 0);
        return res;
    }

    private void dfs(String s, List<String> res, StringBuilder ip, int index, int cnt) {
        if (cnt > 4) {
            return;
        }
        if (cnt == 4 && index == s.length()) {
            res.add(ip.toString());
            return;
        }
        for (int i = 1; i < 4; ++i) {
            int end = index + i;
            if (end > s.length()) {
                break;
            }
            String sub = s.substring(index, end);
            if ((sub.startsWith("0") && sub.length() > 1) || Integer.parseInt(sub) > 255) {
                break;
            }
            if (cnt < 3) {
                sub += ".";
            }
            ip.append(sub);
            dfs(s, res, ip, end, cnt + 1);
            ip.delete(ip.length() - sub.length(), ip.length());
        }
    }
}
```
