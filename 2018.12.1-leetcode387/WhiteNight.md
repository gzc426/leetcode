>```java
>import java.util.LinkedHashMap;
>import java.util.Map;
>
>/**
> * 字符串中的第一个唯一字符
> *
> */
>public class S4 {
>    public int firstUniqChar(String s) {
>        Map<Character,Integer> map = new LinkedHashMap<>();
>        char[] chars = s.toCharArray();
>
>        for (int i = 0; i < chars.length; i++) {
>            if (!map.containsKey(chars[i])){
>                map.put(chars[i], i);
>            }
>            else{
>                map.put(chars[i], -1);
>            }
>        }
>
>        for (Map.Entry<Character,Integer> entry : map.entrySet()){
>            if (entry.getValue() != -1)
>                return entry.getValue();
>        }
>
>        return -1;
>    }
>    
>    public int firstUniqChar(String s) {
>        int start;
>        int end;
>        int result = s.length();
>
>        for (char i = 'a'; i <= 'z'; i++) {
>            start = s.indexOf(i);
>            end = s.lastIndexOf(i);
>            if (start == end && start != -1){
>                result = Math.min(result,start);
>            }
>        }
>
>        if (result == s.length())
>            return -1;
>        else
>            return result;
>    }
>
>    public static void main(String[] args) {
>        S4 s = new S4();
>        String s1 = "leetcode";
>        String s2 = "loveleetcode";
>        int res1 = s.firstUniqChar(s1);
>        int res2 = s.firstUniqChar(s2);
>        System.out.println(res1);
>        System.out.println(res2);
>    }
>}
>```

