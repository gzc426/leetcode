## 451_(根据字符出现频率排序)Sort Characters by Frequency
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
### 1.2 输入与输出
输入：
* string s:给定的字符串s

输出：
* string:字符串里的字符按照出现的频率降序排列后的字符串
### 1.3 样例
#### 1.3.1 样例1
输入:"tree"<br>
输出:"eert"<br>
解释:'e'出现两次，'r'和't'都只出现一次。因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
#### 1.3.2 样例2
输入:"cccaaa"<br>
输出:"cccaaa"<br>
解释:'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。注意"cacaca"是不正确的，因为相同的字母必须放在一起。
#### 1.3.3 样例3
输入:"Aabb"<br>
输出:"bbAa"<br>
解释:此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。注意'A'和'a'被认为是两种不同的字符。

## 2 思路描述与代码    
### 2.1 思路描述（哈希表+桶排序）
1. 先把数组所有元素插入哈希表
2. 遍历哈希表, 插入桶中, 桶的下标是哈希表的关键字的个数, 桶的值是哈希表的关键字
3. 从桶末尾开始遍历桶,将每个桶中的元素和个数插入结果字符串中

比如输入"tree"
遍历插入哈希表map后，map = {'t':1, 'r':1, 'e':2 }（顺序是乱的）, 其中't':1代表't'出现了1次<br>
然后遍历哈希表，插入桶中(通下标是字符出现的个数-1，桶值是哈希表的字符)，有桶bucket = [['r','t'], ['e'], [null], [null]]<br>
从未尾巴开始遍历桶，得到字符串'eert'
### 2.2 代码
```cpp
//函数中涉及到的c++知识
//vector<int> 是个长度可变的int数组，c++里面称为容器
//vector<vector<int>> 是个长度可变且长度不一的二维int数组，每行又是一个长度可变的int数组
//ret_func_type func(vector<int>& name) 中的name是vector<int>容器的引用，可以理解为传入一个指针
//unordered_map<int, int> map是一个无序哈希表，哈希的键值key是唯一的
//map[val]就是获得val在哈希表map中的个数
string frequencySort(string s) {
    unordered_map<char, int> map;
    //1. 先插入哈希表
    for( int i = 0; i < s.size(); i++ ) map[s[i]]++;
    
    vector<vector<int>> bucket(s.size());
    //2. 桶排序
    //it->second是字符出现的个数，it->first是字符
    for (auto it = map.begin(); it != map.end(); ++it) bucket[it->second - 1].push_back(it->first);
    //3. 遍历桶
    string ans;
    for( int i = bucket.size() - 1; i >= 0; i-- ){
        if(bucket[i].size() != 0){
            for( int j = 0; j < bucket[i].size(); j++ ){
                ans.insert(ans.end(), i+1, bucket[i][j]);
            }
        }
    }
    return ans;
}

```
## 3 思考与拓展
### 3.1 思考
本题使用桶排序使得时间复杂度降低为O(n)，此外可以使用快排对哈希表统计的字符频率进行排序。本题与[347_(前K个高频元素)Top K Frequent Element](https://leetcode-cn.com/problems/top-k-frequent-elements/)思路基本一致。
#### 3.1.1 其他方法
#### 3.1.1.1 哈希表+快排
1. 先把数组所有元素插入哈希表
2. 队列节点的结构是{字符出现的个数，字符}，对哈希表统计的字符频率从大到小进行快排（以字符出现的个数从大到小排列）中。
3. 遍历排序后的数据，获得排列后的字符串

#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
哈希表+桶排序|O(n)|O(n)
哈希表+快排|O(n)|O(nlogn)

#### 3.1.3 难点分析
1. 在插入哈希表后，需要选择以关键字还是关键字的个数来作为排序的依据

### 3.2 拓展
如果给你的是链表数据会影响他的时间与空间复杂度吗？
