## 557_(反转字符串中的单词 III)Reverse Words in a String III
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。<br>
__注意__：<br>
在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
### 1.2 输入与输出
输入：
* string s：输入的字符串s

输出：
* string:反转字符串后的字符串
### 1.3 样例
#### 1.3.1 样例1
输入: "Let's take LeetCode contest"<br>
输出: "s'teL ekat edoCteeL tsetnoc" 
## 2 思路描述与代码	
### 2.1 思路描述（单词反转法）
start 记录字符串中每个单词的起始位置
```cpp
for( c in String s which is s[i]){
    if(c == ' '){
        reverse s.substr(start, i);
        start = i + 1;
    }
}
```
### 2.2 代码
```cpp
string reverseWords(string s) {
    s += ' ';
    int len = s.size();
    int start = 0;
    for( int i = 0; i < len; i++ ){
        if(s[i] == ' '){
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }
    s.pop_back();
    return s;
}
```
## 3 思考与拓展
### 3.1 思考
#### 3.1.1 其他方法
无。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
单词反转法|O(1)|O(n)
#### 3.1.3 难点分析
1. 如何记录起始位置
2. 如何处理字符串的最后一个单词
### 3.2 拓展
如果给你的是链表数据或者数组数据呢？
