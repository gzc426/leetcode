##### 题目
```
给定一组字符，使用原地算法将其压缩。

压缩后的长度必须始终小于或等于原数组长度。

数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。

在完成原地修改输入数组后，返回数组的新长度。
```
##### 思路
设置两个指针i  和  j
i是赋值指针
j用来统计每次字符出现的次数

**难点**
当次数为两位数时的写入

```
char[] temArray=String.valueOf(count).toCharArray();
int k=0;
while (k<temArray.length) {
    chars[i++]=temArray[k++];
}
```
一位数时的int和char转换

```
chars[i++]=(char) (count + '0');
```

##### 代码
```
class Solution {
    public int compress(char[] chars) {
        /**
         * 思路：
         * 遍历数组  统计每个字符出现的次数
         */
        int length=chars.length;//数组长度
        if (length<=1) {
            return length;
        }

        
        int i=0,j=i,count=0;
        char temChar=chars[j];
        //i是赋值指针
        //j是计数指针  
        while(j<length){
            temChar=chars[j];
            //个数和temChar相等的字符的个数
            while(j<length && chars[j]==temChar){
                j++;
                count++;
            }
            //当个数为1时  直接把temChar赋给数组chars
            if (count==1) {
                chars[i++]=temChar;
            }else {
                chars[i++]=temChar;
                //当个数为一位数
                if (count<10) {
                    chars[i++]=(char) (count + '0');
                }else{//当个数大于一位数  借助字符数组
                    char[] temArray=String.valueOf(count).toCharArray();
                    int k=0;
                    while (k<temArray.length) {
                        chars[i++]=temArray[k++];
                    }
                }
            }
            count=0;
        }
        return i;
    }
}
```

