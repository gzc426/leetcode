## 890_(查找和替换模式)Find and Repalce Pattern
## 1 问题描述、输入输出与样例
### 1.1 问题描述
你有一个单词列表 words 和一个模式  pattern，你想知道 words 中的哪些单词与模式匹配。<br>
如果存在字母的排列 p ，使得将模式中的每个字母 x 替换为 p(x) 之后，我们就得到了所需的单词，那么单词与模式是匹配的。<br>
（回想一下，字母的排列是从字母到字母的双射：每个字母映射到另一个字母，没有两个字母映射到同一个字母。）<br>
返回 words 中与给定模式匹配的单词列表。<br>
你可以按任何顺序返回答案。<br>
__提示__：<br>
1. 1 <= words.length <= 50<br>
2. 1 <= pattern.length = words[i].length <= 20<br>
### 1.2 输入与输出
输入：<br>
* vector<string>& words：给定的单词列表<br>
* string pattern：模式单词<br>
输出：<br>
* vector<string>：与给定模式匹配的单词列表<br>
	
### 1.3 样例
#### 1.3.1 样例1
输入: <br>
words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"<br>

输出: <br>
["mee","aqq"]<br>
	
解释：<br>
"mee" 与模式匹配，因为存在排列 {a -> m, b -> e, ...}。<br>
"ccc" 与模式不匹配，因为 {a -> c, b -> c, ...} 不是排列。
因为 a 和 b 映射到同一个字母。<br>
## 2 思路描述与代码    
### 2.1 思路描述（双字典方法）
对每个属于单词列表words的单词word，使用dict1 记录 word 中的字符 word[i] 对 pattern 字符 pattern[i] 的映射<br>
使用dict2 记录 pattern 中的字符 pattern[i] 对 word 字符 word[i] 的映射<br>
```cpp  
for(word in words){
    初始化字典映射;
    for(word[i] in word){
        if(word[i] 未被映射)
            if(pattern[i] 未被映射) 双方记录映射关系;
            else 确认 pattern[i] 映射的对象是不是 word[i]，如果不是则失败;
        if(word[i] 已被映射 且 映射对象不是 pattern[i]) 则失败;
    } 
    如果成功，记录word;
}
``` 

### 2.2 代码
```cpp	
vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> ans;
    for( auto word : words ){
        // dict1 记录 word 中的字符对 pattern 字符的映射
        // dict2 记录 pattern 中的字符对 word 字符的映射
        vector<int> dict1(127, -1);
        vector<int> dict2(127, -1);
        int word_len = word.size();
        int fail = 0;
        for( int i = 0; i < word_len; i++ ){
            // 如果 word[i] 未被映射
            // (i) 如果 pattern[i] 未被映射，双方记录映射关系
            // (ii) 如果 pattern[i] 已被映射，确认 pattern[i] 映射的对象是不是 word[i]，如果不是则失败
            if(dict1[word[i]] == -1){
                if(dict2[pattern[i]] == -1){
                    dict1[word[i]] = pattern[i];
                    dict2[pattern[i]] = word[i];
                }
                else if(dict2[pattern[i]] != word[i]){
                    fail = 1;
                    break ;
                }
            }
            // 如果 word[i] 已被映射 且 映射对象不是 pattern[i]，则失败
            else if(dict1[word[i]] != -1 && dict1[word[i]] != pattern[i]){
                fail = 1;
                break ;
            } 
        }
        //如果成功，记录word
            if(!fail) ans.push_back(word);
        }
        return ans;
    }
```
## 3 思考与拓展
### 3.1 思考
#### 3.1.1 其他方法
无。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
双字典方法|O(1)|O(kn),k为word的长度，n为words的数目
#### 3.1.3 难点分析
1. 如何记录二者的映射关系；
2. 如何分辨映射存在一对多、多对一和多对多情况的出现。

### 3.1 扩展
本题需要使用两个字典记录映射关系，不然可能导致一对多或者多对一情况。

