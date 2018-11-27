## 151_(反转字符串里的单词)Reverse Words in a String
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个字符串，逐个翻转字符串中的每个单词。<br>

__说明__:<br>
* 无空格字符构成一个单词。
* 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
* 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

__进阶__: <br>
* 请选用C语言的用户尝试使用 O(1) 空间复杂度的原地解法。
### 1.2 输入与输出
输入：
* string &s:给定的字符串s

输出：
* void:原地修改
### 1.3 样例
#### 1.3.1 样例1
输入: "the sky is blue"<br>
输出: "blue is sky the"
## 2 思路描述与代码	
### 2.1 思路描述（反转法）
1. 先整体反转
2. 按单词逐个反转

比如输入: "the sky is blue"<br>
整体反转后为"elub si yks eht"<br>
按单词逐个反转后为"blue is sky the"<br>
### 2.2 代码
```cpp
void reverseWords(string &s) {
    //强行头部加空格方便统一处理
    s.insert(0, 1, ' ');
    reverse(s.begin(), s.end());
    int len = s.size();
    //搜索的位置
    int search = 0;
    //搜索的当前单词的长度
    int cnt_word = 0;
    //搜索的当前单词的起始位置
    int start_word = 0;
    while( search < len ){
        //在单词有效范围内
        if(s[search] != ' ') ++search, ++cnt_word;
        //在单词边界
        else{
            if(cnt_word != 0){
                //翻转单词
                reverse(s.begin() + start_word, s.begin() + start_word + cnt_word);
                //去除多余的空格
                search++;
                while(search < len && s[search] == ' ') s.erase(s.begin() + search);
                //设置下一个单词搜索的初始位置和长度
                start_word = search;
                cnt_word = 0;
            }
            //可以去除原字符串中开头和尾巴可能存在的连续空格
            else s.erase(s.begin() + start_word);
        }
    }
    //去除空格最后一个单词附带的空格
    s.pop_back();
}
```
## 3 思考与拓展
### 3.1 思考
#### 3.1.1 其他方法
无。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
反转法|O(1)|O(n)
#### 3.1.3 难点分析
1. 思路分析
2. 原地修改
### 3.2 拓展
如果给你的是数组数据呢？
