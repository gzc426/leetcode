```
class Solution {
    public String reverseWords(String s) {
        String [] a = s.split(" ");
        String ss = "";
        for (int i = 0; i < a.length; i++){
            StringBuffer sb = new StringBuffer(a[i]);
            ss = ss + sb.reverse().toString() + " ";
        }
        return ss.substring(0, ss.length()-1);   
    }
}
```
