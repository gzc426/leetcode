## 058_(最后一个单词的长度)Length of Last Word
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。<br>
如果不存在最后一个单词，请返回 0 。

__说明__：一个单词是指由字母组成，但不包含任何空格的字符串。

### 1.2 输入与输出
输入：<br>
* string s：仅包含大小写字母和空格 ' ' 的字符串 s<br>
输出：<br>
* int：最后一个单词的长度
	
### 1.3 样例
#### 1.3.1 样例1
输入: "Hello World"<br>
输出: 5

#### 1.3.2 样例2
输入: "Hello      "<br>
输出: 5	

## 2 思路描述与代码    
### 2.1 思路描述（单词计数法）	 
cnt_last_word 为对单词的计数值
```cpp
cnt_last_word = 0;
i = 0;
while( i < len(s) ){
    if(s[i] == ' '){
        Skip consecutive 0;
        //case like 1.3.2
        if(s[i] is the last charater of s) return cnt_last_word;
        else clear cnt_last_word;
    }
    else ++cnt_last_word
}
//case like 1.3.1
return cnt_last_word;
```
### 2.2 代码
```cpp
int lengthOfLastWord(string s) {
	int s_len = s.size();
	int cnt_last_word = 0;
	int i = 0;
	while( i < s_len ){
		if(s[i] == ' ') {
			//跳过重复的 ' '
			while( i + 1 < s_len && s[i + 1] == ' ') i++;
			//如果最后一个也是 ' ',返回连续的 '' 前的单词的长度
			if(i == s_len - 1) return cnt_last_word;
			else cnt_last_word = 0;  
		}
		//否则加1
		else ++cnt_last_word;
		++i;
	}
	return cnt_last_word;
}
```

## 3 思考与拓展
### 3.1 思考
本题较为简单，在增加 1.3.2 样例2 的特殊处理后即可。 
#### 3.1.1 其他方法
无。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
单词计数法|O(1)|O(n)
#### 3.1.3 难点分析
1. 跳跃重复的' '
2. 需要考虑字符串 s 的尾巴是以一段连续的 ' ' 结尾
### 3.2 拓展
如果给你的数据是链表或者数组数据呢？
