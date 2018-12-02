```
import java.util.*;
class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> result = new ArrayList();
        String p = transfor(pattern);
        String w;
        String ww;
        for (int i = 0; i < words.length; i++){
            w = words[i];
            ww = transfor(w);
            if (ww.equals(p)){
                result.add(w);
            }

        }
        return result;
    }

    private String transfor(String s){
        Map<Character, Character> m = new HashMap<>();
        char j = 0;
        String ss = "";
        m.put(s.charAt(0), (char)(j + '0'));
        for(int i = 1; i < s.length(); i++){
            if (s.charAt(i-1) != s.charAt(i)){
                if (m.containsKey(s.charAt(i))){
                    ss += m.get(s.charAt(i));
                }
                else {
                    ++j;
                    ss += (char)(j+'0');
                    m.put(s.charAt(i), (char)(j + '0'));
                }
            }
        }
        return ss;
    }
}
```
