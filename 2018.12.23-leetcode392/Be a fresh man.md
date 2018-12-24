## 392_(判断子序列)Is Subsequence
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。<br>
你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。<br>
字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

__后续挑战__ :<br>
如果有大量输入的 S，称作S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

### 1.2 输入与输出
输入：
* string s:给定的字符串 s
* string t:给定的字符串 t

输出：
* bool:判断 s 是否为 t 的子序列
### 1.3 样例
#### 1.3.1 样例1
输入: s = "abc", t = "ahbgdc"<br>
输出: true
#### 1.3.2 样例2
输入: s = "axc", t = "ahbgdc"<br>
输出: false
## 2 思路描述与代码	
### 2.1 思路描述（双下标法）
i为字符 s 的遍历下标， j 表示字符 t 的遍历下标
```cpp
for( j = 0; j < len_t; j++ ){
    if(s[i] == t[j]){
        if(i == len_s - 1) return true;
        else i++;
    }
}
```
比如输入: s = "abc", t = "ahbgdc"；<br>
j = 0, i = 0, s[0] == t[0], i = 1; <br>
j = 1, i = 1, s[1] != t[1]; <br>
j = 2, i = 1, s[1] == t[2], i = 2; <br>
j = 3, i = 2, s[1] != t[3]; <br>
j = 4, i = 2, s[2] != t[4]; <br>
j = 5, i = 2, s[2] == t[5], 返回true;
### 2.2 代码
```cpp
bool isSubsequence(string s, string t) {
    int len_s = s.size();
    int len_t = t.size();
    //边界情况
    if(len_s > len_t) return false;
    else if(len_s == 0) return true;
    
    //遍历t
    int i = 0, j = 0;
    for( j = 0; j < len_t; j++ ){
        //如果当前字符相等，查找 s 的下一个字符是否在 t 中
        if(s[i] == t[j]){
            if(i == len_s - 1) return true;
            else i++;
        }
    }
    return false;
}
```
## 3 思考与拓展
### 3.1 思考
本题按照子序列的定义并利用双下标法可以很容易解决。
#### 3.1.1 其他方法
无。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
双下标法|O(1)|O(s_len+t_len)
#### 3.1.3 难点分析
1. i下标的更新。

### 3.2 拓展
如果给你的是数组数据呢？
