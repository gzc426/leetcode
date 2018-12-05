>```java
>/**
> * leetcode58 最后一个单词的长度
> *
> */
>public class S5 {
>    public int lengthOfLastWord(String s) {
>        String[] string = s.split(" ");
>        if (string == null || string.length == 0)
>            return 0;
>        int i = string.length - 1;
>        return string[i].length();
>    }
>
>    public static void main(String[] args) {
>        S5 s = new S5();
>        String string = "Hello World";
>        int res = s.lengthOfLastWord(string);
>        System.out.println(res);
>    }
>}
>```

