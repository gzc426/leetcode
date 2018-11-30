##### 题目
```
给定一个字符串，逐个翻转字符串中的每个单词。

示例:  

输入: "the sky is blue",
输出: "blue is sky the".

说明:

    无空格字符构成一个单词。
    输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
    如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

进阶: 请选用C语言的用户尝试使用 O(1) 空间复杂度的原地解法。
```
##### 思路
- 先将整个字符串反转
- 按照空格分成String数组
- 每个单词反转
##### 代码

```
public class Solution {
    public String reverseWords(String s) {
        int length=s.length();
        //当字符串为空
        if(s == null){ return null;}
        //当字符串为"    "时 直接返回null
        if(s.trim().equals("")){
            return s.trim();   
        }

        //1.反转整个字符串
        String allRevStr=ReverseWord(s);
        //2.获得每个单词
        String[] strChar=allRevStr.split(" ");

        //3.反转每个字符串
        String reverse="";
        for (int i=0; i<strChar.length; ++i) { 
            String temp=ReverseWord(strChar[i]);
            if (temp.equals("")) {
                continue;
            }
            
            if (i==strChar.length-1) {
                reverse=reverse+temp;
            }else{
                reverse=reverse+temp+" ";
            }
        }
        return reverse;
    }

    String ReverseWord(String s){
        //删除字符串前序和后继中的空格
        String str=s.trim();
        if (str.length()==1) {
            return str;
        }else if (str.equals("")) {
            return "";
        }else{
            StringBuilder sb=new StringBuilder(str);
            String revStr=sb.reverse().toString();
            return revStr;
        }
    }
    
}
```

##### 改进方法

```
public class Solution {
    public String reverseWords(String s) {
        int length=s.length();
        //当字符串为空
        if(s == null){ return null;}
        //当字符串为"    "时 直接返回null
        if(s.trim().equals("")){
            return s.trim();   
        }
        /**
         * 先将字符串按照空格分裂为字符串数组
         * 然后收尾两个指针来交换即可
         */
        //0.掐头去尾
        String allRevStr=s.trim();
        //1.将字符串按照空格分裂为字符串数组
        String[] strChar=allRevStr.split(" ");

        //2.使用首尾两个指针来交换
        int left=0;
        int right=strChar.length-1;
        String temStr=null;
        while(left<right){
            //交换
            temStr=strChar[left];
            strChar[left]=strChar[right];
            strChar[right]=temStr;
            //移动指针
            left++;
            right--;
        }
        //3.拼接好新的字符串
        String reverse="";
        for (int i=0; i<strChar.length; ++i) { 
            //对每一个单词掐头去尾
            String temp=strChar[i].trim();
            
            if (temp.equals("")) {
                continue;
            }

            if (i==strChar.length-1) {
                reverse=reverse+temp;
            }else{
                reverse=reverse+temp+" ";
            }
        }
        return reverse;
    }
}
```
