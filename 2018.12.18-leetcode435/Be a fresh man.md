## 435_(无重叠区间)Non-overlapping Intervals
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。<br>
__注意__:
1. 可以认为区间的终点总是大于它的起点。
2. 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
### 1.2 输入与输出
输入：
* vector< Interval >& intervals:输入的区间列表

输出：
* int:需要移除区间的最小数量
### 1.3 样例
#### 1.3.1 样例1
输入: [ [1,2], [2,3], [3,4], [1,3] ]<br>
输出: 1<br>
解释: 移除 [1,3] 后，剩下的区间没有重叠。
#### 1.3.2 样例2
输入: [ [1,2], [1,2], [1,2] ]<br>
输出: 2<br>
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
#### 1.3.2 样例3
输入: [ [1,2], [2,3] ]<br>
输出: 0<br>
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。

## 2 思路描述与代码	
### 2.1 思路描述（贪心法）
贪心原则：对于重叠的两个区间，删去两个区间中右边界较大的那个能使得移除区间的数量最小

比如输入[[1,3], [2,5], [4,6]];<br>
排序后区间列表为[[1,3], [2,5], [4,6]];<br>
初始化删除重叠区间后的最后一个无重叠区间pre = [-2^31, -2^31];<br>
初始化删去的区间数目cnt = 0;<br>
对于区间[1,3]，与[-2^31, -2^31]无重叠，pre = [1,3], cnt = 0;<br>
对于区间[2,5]，与[1,3]有重叠，根据贪心原则删去[2,5]，pre = [1,3], cnt = 1;<br>
对于区间[4,6]，与[1,3]无重叠，pre = [4,6], cnt = 1;<br>
返回cnt = 1;
### 2.2 代码
```cpp
//函数中涉及到的c++知识
//vector<Interval> 是个长度可变的Interval数组，c++里面称为容器
//ret_func_type func(vector<Interval>& name) 中的name是vector<Interval>容器的引用，可以理解为传入一个指针
//sort(g.begin(), g.end(), cmp) 对容器g的Interval元素从小到大排序，容器的起始数据的指针是 g.begin(),容器的末尾数据的指针是g.end()

//按照区间左边界升序排序
bool cmp(const Interval& data1, const Interval& data2){
    return (data1.start < data2.start);
}

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int cnt_erase = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        //前一个不重复区间的开始与结束
        int start = -1<<31, end = -1<<31;
        for( int i = 0; i < intervals.size(); i++ ){
            //如果两个区间没有重叠
            if(intervals[i].start >= end){
                start = intervals[i].start;
                end   = intervals[i].end;
            }
            //重叠
            else{
                //如果当前区间在区间内，则移除大的区间
                //不在区间内则删除当前区间，这样子删去的区间最少
                if(intervals[i].end <= end){
                    start = intervals[i].start;
                    end   = intervals[i].end;
                }
                cnt_erase++;
            }
        }
        return cnt_erase;
    }
};
```
## 3 思考与拓展
### 3.1 思考
本题选取好准确的贪心原则后即可简单的解决该问题。
#### 3.1.1 其他方法
无。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
贪心法|O(1)|O(nlogn)
#### 3.1.3 难点分析
1. 先要对区间排序，注意区间排序的原则;
2. 选取准确的贪心原则。

### 3.2 拓展
1. [合并区间](https://leetcode-cn.com/problems/merge-intervals/);
2. [插入区间](https://leetcode-cn.com/problems/insert-interval/).
