```
public class Solution {
    public int lengthOfLastWord(String s) {
        String[] tt;
        tt = s.split(" ");
        return tt.length == 0?0:tt[tt.length-1].length();
    }
}
```
