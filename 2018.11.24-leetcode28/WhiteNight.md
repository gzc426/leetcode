>```java
>/**
> * 实现strStr()
> *
> */
>public class S1 {
>//    public int strStr(String haystack, String needle) {
>//        //直接调用indexof()
>//        return haystack.indexOf(needle);
>//    }
>
>    public int strStr(String haystack, String needle) {
>        if (needle.length() == 0)
>            return 0;
>
>        char[] charArrayHaystack = haystack.toCharArray();
>        char[] charArrayNeedle = needle.toCharArray();
>
>        for (int i = 0; i < charArrayHaystack.length; i++) {
>            if (charArrayHaystack[i] == charArrayNeedle[0]){
>                int j = i + 1;
>                int k = 1;
>                for (;k < charArrayNeedle.length && j < charArrayHaystack.length; k++) {
>                    if (charArrayHaystack[j] == charArrayNeedle[k])
>                        j++;
>                    else
>                        break;
>                }
>                if (k == charArrayNeedle.length)
>                    return i;
>            }
>        }
>
>        return -1;
>    }
>
>    public static void main(String[] args) {
>        S1 s = new S1();
>        int res = s.strStr("hello","ll");
>        System.out.println(res);
>    }
>}
>```

