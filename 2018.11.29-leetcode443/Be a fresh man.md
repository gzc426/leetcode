## 443_(压缩字符串)String Compression
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一组字符，使用原地算法将其压缩。<br>
压缩后的长度必须始终小于或等于原数组长度。<br>
数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。<br>
在完成原地修改输入数组后，返回数组的新长度。<br>
__注意__：<br>
所有字符都有一个ASCII值在[35, 126]区间内。
1 <= len(chars) <= 1000。
### 1.2 输入与输出
输入：
* vector<char>& chars：输入的字符列表

输出：
* int:原地压缩后的字符串的列表长度
### 1.3 样例
#### 1.3.1 样例1
输入：<br>
["a","a","b","b","c","c","c"]<br>
输出：<br>
返回6，输入数组的前6个字符应该是：["a","2","b","2","c","3"]<br>
说明：<br>
"aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代。<br>
#### 1.3.2 样例2
输入：<br>
["a"]<br>
输出：<br>
返回1，输入数组的前1个字符应该是：["a"]<br>
说明：<br>
没有任何字符串被替代。<br>
#### 1.3.3 样例2
输入：<br>
["a","b","b","b","b","b","b","b","b","b","b","b","b"]<br>
输出：<br>
返回4，输入数组的前4个字符应该是：["a","b","1","2"]。<br>
说明：<br>
由于字符"a"不重复，所以不会被压缩。"bbbbbbbbbbbb"被“b12”替代。<br>
注意每个数字在数组中都有它自己的位置。

## 2 思路描述与代码	
### 2.1 思路描述（计数方法）
思路很清晰，这里就不举例了，思路采用计数方法。<br>
start 记录当前搜索字符的起始下标， search 记录当前搜索字符的遍历下标 ， cnt_same_char 记录当前搜索字符的相同长度<br>
cmpr_len_char 记录当前压缩了的字符串的长度， len 记录输入字符串的长度<br>
```cpp
while( search < len ){
　　if(当前字符和前一个字符相同) cnt_same_char++；
    else{
        记录当前单词和数目
        start = search;
        cnt_same_char = 1;
    } 
    search++;
}
```
### 2.2 代码
```cpp
int compress(vector<char>& chars) {
    //强行添加空格方便统一处理
    chars.push_back(' ');
    int len = chars.size();
    int start = 0, search = 1;
    int cnt_same_char = 1, cmpr_len_char = 0;
    while( search < len ){
        if(chars[search] == chars[search - 1]) ++cnt_same_char;
        else{
            chars[cmpr_len_char++] = chars[start];
            //当前char计数值大于1时才压缩
            if(cnt_same_char > 1){
                //整形转字符串
                //从高位往低位转 遇见最高位后flag = 1;
                int flag = 0;
                int msb = 1000, cnt2char = cnt_same_char;
                for( int i = 0; i < 4; i++ ){
                    int weight = cnt2char / msb;
                    if(weight > 0 || flag) flag = 1, chars[cmpr_len_char++] = weight + '0';
                    cnt2char = cnt2char % msb;
                    msb = msb / 10;
                }
            }
            start = search;
            cnt_same_char = 1;
        }
        search++;
    }
    //去除空格，恢复原始数据
    chars.pop_back();
    return cmpr_len_char;
}
```
## 3 思考与拓展
### 3.1 思考
#### 3.1.1 其他方法
无。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
计数方法|O(1)|O(n)
#### 3.1.3 难点分析
1. 原地修改
2. 整形数据转字符串
### 3.2 拓展
如果给你的数链表数据呢？
