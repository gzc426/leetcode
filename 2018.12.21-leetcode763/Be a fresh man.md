## 763_(划分字母区间)Partition Labels
## 1 问题描述、输入输出与样例
### 1.1 问题描述
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。<br>
返回一个表示每个字符串片段的长度的列表。<br>
__注意__:<br>
1. S的长度在[1, 500]之间。
2. S只包含小写字母'a'到'z'。
### 1.2 输入与输出
输入：
* string S:带划分的字符串 S

输出：
* vector< int>:划分为尽可能多的片段， 每个字符串片段的长度的列表
### 1.3 样例
#### 1.3.1 样例1
输入: S = "ababcbacadefegdehijhklij"<br>
输出: [9,7,8]<br>
解释:划分结果为 "ababcbaca", "defegde", "hijhklij"。<br>
每个字母最多出现在一个片段中。像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。

## 2 思路描述与代码	
### 2.1 思路描述（一遍扫描+切割法）
说明:
* `vector<int>` data; 是个长度可变的 int 数组，c++里面称为容器
* data.empty() 判断 data 是否为空 
* `vector<int>` data(26, -1); 初始化一个长度为26的长度可变 int 数组，且所有元素初始化为 -1

使用`vector< int>` ans记录最终的划分方案;<br>
使用`vector<int>` border 记录每个划分字母区间的右边界所处的下标；<br>
使用`vector<int>` dict(26, -1) 记录每个字符第一次出现的位置;<br>
```cpp
for( int i = 0; i < S.size(); i++ ){
    if(该字母在之前出现过)
    * 合并包括该字母第一次出现位置的区间到当前位置的所有区间;
    else 如果未出现则记录其第一次出现位置;
    当前位置作为最后一个字母区间的右边界;
}
找出最多分段的区间右边界后，对其进行切割即可;
```

比如输出S = "ababc";<br>
S[0] = 'a', border = [], dict['a'] = -1, 'a'未出现过, dict['a'] = 0, border = [0];<br>
S[1] = 'b', border = [0], dict['b'] = -1, 'b'未出现过, dict['a'] = 1, border = [0, 1];<br>
S[2] = 'a', border = [0, 1], dict['a'] = 0, 'a'出现过, 合并区间, border = [2];<br>
S[3] = 'b', border = [2], dict['b'] = 1, 'b'出现过, 合并区间, border = [3];<br>
S[4] = 'c', border = [3], dict['c'] = -1, 'c'出现过, dict['c'] = 4, border = [3, 4];<br>
然后进行切割，将S = "ababc" 从位置3、4分别切割一刀，划分成 "abab" 与 "c"。

### 2.2 代码
```cpp
//一遍扫描+切割法
vector<int> partitionLabels(string S) {
    vector<int> ans;
    int len = S.size();
    //记录每个划分字母区间的右边界所处的下标
    vector<int> border;
    //记录字母第一次出现的位置
    vector<int> dict(26, -1);
    for( int i = 0; i < len; i++ ){
        //如果该字母在之前出现过
        if(dict[S[i] - 'a'] != -1){
            //合并该字母第一次出现位置到当前位置的所有区间
            while(!border.empty() && dict[S[i] - 'a'] <= border.back()) border.pop_back();
        }
        //如果未出现记录位置
        else dict[S[i] - 'a'] = i;
        //当前位置作为最后一个字母区间的右边界
        border.push_back(i);
    }
    //找出最多分段的区间右边界后，对其进行划分即可
    int len_border = border.size();
    ans.push_back(border[0] + 1);
    for( int i = 1; i < len_border; i++ ){
        ans.push_back(border[i] - border[i - 1]);
    }
    return ans;
}
```
## 3 思考与拓展
### 3.1 思考
一遍扫描+切割法利用的是字符第一次出现的位置，也可以利用字符最后一次出现的位置的做为突破点。
#### 3.1.1 其他方法
##### 3.1.1.1 两遍扫描法
首先遍历一遍记录 S 中出现字母的最后一个下标;<br>
再一遍扫描确认最佳分割方案。
```cpp
vector<int> partitionLabels(string S) {
    vector<int> ans;
    int len = S.size();
    vector<int> dict(26, -1);
    for( int i = 0; i < len; i++ ){
        dict[S[i] - 'a'] = i;
    }
    //记录当前分割区间的开始与结束下标
    int interval_start = 0;
    int interval_end = -1;
    for( int i = 0; i < len; i++ ){
        //扩张右边界
        interval_end = max(interval_end, dict[S[i] - 'a']);
        //到达右边界的结束位置了
        if(i == interval_end){
            ans.push_back(interval_end - interval_start + 1);
            interval_start = interval_end + 1;
        }
    }
    return ans;
}
```
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
一遍扫描+切割法|O(n)|O(n)，最坏情况与两遍扫描法时间复杂度一致
两遍扫描法|O(1)|O(n)
#### 3.1.3 难点分析
1. 选取字母第一次还是最后一次出现的位置作为入手点;
2. 根据什么规则判断到了右边界。

### 3.2 拓展
如果给你的是链表数据呢？
