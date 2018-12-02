##### 题目

```
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2

示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1

说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
```
##### 思路
在haystack上找跟needle首字符相等的位置，然后依次与needle剩余的字符进行比较，如果发现不同，将needle的指针归零  将haystack 的指针归到比较遍历的起始加一（j=j-i+1)  然后重复上述操作即可。

##### 代码
```
class Solution {
    public int strStr(String haystack, String needle) {
        char[] hayArray=haystack.toCharArray();
        char[] neeArray=needle.toCharArray();
        int lengthHay=hayArray.length;
        int lengthNee=neeArray.length;
        //如果needle的长度大于haystck的长度 返回-1
        if (needle.equals("")) {
            return 0;
        }
        if (lengthHay<lengthNee) {
            return -1;
        }
        //判定
        int j=0,i=0;
        while(true){
            while(j<lengthHay && hayArray[j]!=neeArray[0]){
                j++;
            }

            if (j+lengthNee>lengthHay) {
                return -1;
            }else{
                while(i<lengthNee){
                    if (hayArray[j]==neeArray[i]) {
                        j++;
                        i++;
                    }else{
                        j=j-i+1;
                        i=0;
                        break;
                    }
                }
            }

            if (i==lengthNee) {
                break;
            }
        }

        return j-lengthNee;
    }
}
```
