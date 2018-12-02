```java
/**
 * 压缩字符串
 *
 */
public class S3 {
    public int compress(char[] chars) {
        int count = 1;
        int index = 0;

        for (int i = 0; i < chars.length; i++) {
            if (i + 1 == chars.length || chars[i] != chars[i+1]){
                chars[index++] = chars[i];
                if (count > 1){
                    String temp = String.valueOf(count);
                    for (int j = 0; j < temp.length(); j++) {
                        chars[index++] = temp.charAt(j);
                    }
                }
                count = 1;
            }
            else
                count++;
        }

        return index;
    }

    public static void main(String[] args) {
        S3 s = new S3();
        char[] chars = {'a','b','b','b','b','b','b','b','b','b','b','b'};
        int res = s.compress(chars);
        System.out.println(res);

        for (int i = 0; i < chars.length; i++) {
            System.out.print(chars[i] + " ");
        }
    }
}
```

