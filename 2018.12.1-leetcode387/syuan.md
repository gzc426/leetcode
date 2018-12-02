##### 题目

```
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:

s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.

 

注意事项：您可以假定该字符串只包含小写字母。
```
##### 解答一

```
class Solution {
    public int firstUniqChar(String s) {
        int length=s.length();
        if (s.equals("")) {
            return -1;
        }
        if (length==1) {
            return 0;
        }

        int i=0;//返回索引
        char temp=s.charAt(0);//用来记录每次要比较的字符
        while (i<length) {
            temp=s.charAt(i);
            int j=0;
            //寻找等于temp的字符
            while(j<length){
                if (temp!=s.charAt(j) || j==i) {
                    j++;
                }else{
                    break;
                }   
            }
            if (j>=length) {
                break;
            }
            i++;
        }
        if (i>=length) {
            return -1;
        }
        return i;
    }
}
```
>这里对于每一个数字必须要从索引0开始  因为有可能他的重复数字在前面
>
>执行时间56ms

##### 解法二

```
class Solution {
    public int firstUniqChar(String s) {
        int[] freq=new int[26];
        for (int i=0; i<s.length(); i++) {
            freq[s.charAt(i)-'a']++;
        }

        for (int i=0; i<s.length(); i++) {
            if (freq[s.charAt(i)-'a']==1) {
                return i;
            }
        }
        return -1;
    }
}
```
执行时间：31ms

