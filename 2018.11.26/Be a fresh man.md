## 125_(验证回文串)Valid Palindrome
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。<br>
__说明__：本题中，我们将空字符串定义为有效的回文串。
### 1.2 输入与输出
输入：
* string s:给定的字符串s

输出：
* bool:是否是回文串
### 1.3 样例
#### 1.3.1 样例1
输入: "A man, a plan, a canal: Panama"<br>
输出: true
#### 1.3.2 样例2
输入: "race a car"<br>
输出: false
## 2 思路描述与代码	
### 2.1 思路描述（双下标一遍扫描）
start记录扫描的左边界，end记录扫描的右边界<br>
分别跳跃无效字符并比较二者是否是相等或者是大小写关系，如果不是则返回false，依次比较直到 start >= end 。
### 2.2 代码
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        int start = 0, end = len - 1;
        while( start < end ){
            //跳过无效字符
            while(start < end && (s[start] < '0' || (s[start] > '9' && s[start] < 'A') ||  (s[start] > 'Z' && s[start] < 'a') || s[start] > 'z')) start++;
            while(start < end && (s[end] < '0' || (s[end] > '9' && s[end] < 'A') ||  (s[end] > 'Z' && s[end] < 'a') || s[end] > 'z')) end--;
            //cout << start << " " << end << endl;
            //比较是否对称
            if(((s[start] >= '0' && s[start] <= '9') || (s[end] >= '0' && s[end] <= '9')) && s[start] != s[end]) return false;
            if(s[start] != s[end] && abs(s[start] - s[end]) != 32) return false;
            start++, end--;
        }
        return true;
    }
};
```
## 3 思考与拓展
### 3.1 思考
#### 3.1.1 其他方法
无。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
双下标一遍扫描|O(1)|O(n)
#### 3.1.3 难点分析
1. 跳跃无效字符；
2. 若要是有一个字符为数字则二者应该要相等，否则肯定都是字母，判断是否是同一个字符或者大小写字符。
### 3.2 拓展
回文系列的题目有很多，但基本都是利用对称性解决问题。
