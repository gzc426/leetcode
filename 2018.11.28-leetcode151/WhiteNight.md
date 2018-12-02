```java
/**
 * 翻转字符串里面的单词
 *
 */
public class S2 {
    public String reverseWords(String s) {
        if (s == null || s.length() == 0)
            return "";

        String[] string = s.split(" ");
        String res = "";

        for (int i = string.length - 1; i >= 0; i--) {
            if (!string[i].equals("")){
                if (res.length() > 0){
                    res += " ";
                }
                res += string[i];
            }
        }

        return res;
    }

    public static void main(String[] args) {
        S2 s = new S2();
        String string = "the sky is blue";
        String res = s.reverseWords(string);
        System.out.println(res);
    }
}
```