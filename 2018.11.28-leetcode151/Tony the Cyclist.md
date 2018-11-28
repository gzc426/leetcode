```
public class Solution {
    public String reverseWords(String s) {
        s = s.trim();
        System.out.println(s);
        if (s.equals("")){
            return "";
        }
        ArrayList<String> ss = new ArrayList(Arrays.asList(s.split(" ")));
        int len = ss.size();
        for (int i = 0; i < len; i++) {
            if (ss.get(i).equals("")) {
                ss.remove(i);
                i--;
                len--;
            }
        }
        Collections.reverse(ss);
        String result = "";
        for (String i : ss) {
            result = result + i + " ";
        }
        return result.substring(0, result.length() - 1);
    }
}
```
