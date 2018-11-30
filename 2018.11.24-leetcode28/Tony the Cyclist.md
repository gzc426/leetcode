```
class Solution {
    public int strStr(String haystack, String needle) {
        int len = haystack.length();
        int sublen = needle.length();
        for (int i = 0; i < len - sublen + 1; i++){
            if (haystack.substring(i, i + sublen).equals(needle)){
                return i;
            }
        }
        return -1;
    }
}
```
