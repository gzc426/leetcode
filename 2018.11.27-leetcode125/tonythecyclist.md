```
class Solution {
    public boolean isPalindrome(String s) {
        s = s.replaceAll("[ `~!@#$%^&*()+=|{}':;',\\\\[\\\\].<>/?~！@#￥%……&;*（）\"——+|{}【】‘；：”“’。，、？|-]", "").toLowerCase();
        StringBuffer sb = new StringBuffer(s);
        return sb.toString().equals(sb.reverse().toString());
    }
}
```
