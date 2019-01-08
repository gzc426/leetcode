## 744_(寻找比目标字母大的最小字母)Find Smallet Letter Greater Than Target
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个只包含小写字母的有序数组letters 和一个目标字母 target，寻找有序数组里面比目标字母大的最小字母。
数组里字母的顺序是循环的。<br>
举个例子，如果目标字母target = 'z' 并且有序数组为 letters = ['a', 'b']，则答案返回 'a'。

__注__:
1. letters长度范围在[2, 10000]区间内。
2. letters 仅由小写字母组成，最少包含两个不同的字母。
3. 目标字母target 是一个小写字母。
### 1.2 输入与输出
输入：
* vector<_char_>& letters:只包含小写字母的有序数组letters
* char target:目标字母

输出：
* char:有序数组里面比目标字母大的最小字母
### 1.3 样例
#### 1.3.1 样例1
输入:<br>
letters = ["c", "f", "j"]<br>
target = "a"<br>
输出: "c"
#### 1.3.2 样例2
输入:
letters = ["c", "f", "j"]<br>
target = "c"<br>
输出: "f"<br>
#### 1.3.3 样例3
输入:<br>
letters = ["c", "f", "j"]<br>
target = "d"<br>
输出: "f"
#### 1.3.4 样例4
输入:<br>
letters = ["c", "f", "j"]<br>
target = "g"<br>
输出: "j"
#### 1.3.5 样例5
输入:<br>
letters = ["c", "f", "j"]<br>
target = "j"<br>
输出: "c"
#### 1.3.6 样例6
输入:<br>
letters = ["c", "f", "j"]<br>
target = "k"<br>
输出: "c"

## 2 思路描述与代码	
### 2.1 思路描述（两遍扫描法）
1. 第一遍扫描记录出现的字符
2. 第二遍从目标字符的下一个字符开始环形扫描出现的第一个字母

比如输入：letters = ["c", "f", "j"]，target = "j"<br>
第一遍扫描后有:dict["c"]=1, dict["f"]=1, dict["j"]=1, 其余字符的dict都是0;
第二遍扫描从 "h" 开始环形扫描，扫到 "c" 时发现其出现过，于是返回 "c" 。
### 2.2 代码
```cpp
//函数中涉及到的c++知识
//vector<char> 是个长度可变的 char 数组，c++里面称为容器
//vector<int> 是个长度可变的 int 数组，c++里面称为容器
//vector<int> dict(26, 0) 初始化包含26个元素的可变数组为0
char nextGreatestLetter(vector<char>& letters, char target) {
    //字符初始化为未出现
    vector<int> dict(26, 0);
    //一遍扫描记录出现的字符
    int cnt_valid_letter = 0;
    int len = letters.size();
    for( int i = 0; i < len; i++ ){
        if(cnt_valid_letter == 26) continue;
        if(dict[letters[i] - 'a'] == 0){
            dict[letters[i] - 'a'] = 1;
            cnt_valid_letter++;
        }
    }
    //环形扫描比目标字母大的最小字母
    int start = (target - 'a' + 1) % 26;
    for( int i = 0; i < 26; i++ ){
        if(dict[(i+start)%26]) return ((i+start)%26+'a');
    }
    return -1;
}
```
## 3 思考与拓展
### 3.1 思考
本题利用求模操作实现环形扫描，再配合常见的两遍扫描法即可解决该问题。
#### 3.1.1 其他方法
无。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
两遍扫描法|O(1)|O(n)
#### 3.1.3 难点分析
1. 实现环形扫描

### 3.2 拓展
如果给你的数据是链表或者数组数据呢？
