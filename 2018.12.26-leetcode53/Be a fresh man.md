## 053_(最大子序和)Maximum Subarray
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。<br>
__进阶__:
如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

### 1.2 输入与输出
输入：
* vector< int>& nums：给定的整数数组 nums

输出：
* int：最大子序和
	
### 1.3 样例
#### 1.3.1 样例1
输入: [-2,1,-3,4,-1,2,1,-5,4],<br>
输出: 6<br>
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
	
## 2 思路描述与代码    
### 2.1 思路描述（在线处理法）
其思想是如果当前累加的和 this_sum < 0，那么其肯定不会使得后续的子序和更大，所以累加值 this_sum 置 0 重新累加。
```cpp
len_nums 为输入数组的长度
max_sum 为记录的最大和
this_sum 记录当前累加的结果
for( i = 0; i < len_nums; i++ ){
    this_sum += nums[i];
    max_sum = max(max_sum, this_sum);
    if(this_sum < 0) this_sum = 0;
}
```
### 2.2 代码
```cpp
class Solution {
public:
    const int MIN = -2147483648;
    int maxSubArray(vector<int>& nums) {
        return maxSubArray_online_processing(nums);
    }
    //在线处理
    int maxSubArray_online_processing(const vector<int>& nums){
        int len_nums = nums.size();
        int max_sum = MIN;
        int this_sum = 0;
        for( int i = 0; i < len_nums; i++ ){
            this_sum += nums[i];
            max_sum = max(max_sum, this_sum);
            if(this_sum < 0) this_sum = 0;
        }
        return max_sum;
    }
};
```
## 3 思考与拓展
### 3.1 思考
在线处理的时间复杂度为O(n)，此外还有一种方法叫做分治，其空间复杂度为O(nlogn)，二者的思想都值得细细回味。 
#### 3.1.1 其他方法
##### 3.1.1.1 分治法
分治主要有两个步骤，分和治。<br>
把输入的 nums 数组一分为2，递归求左半部分最大子序和 left_max，递归求右半部分的最大子序和right_max，一遍扫描求跨越中间节点的最大子序和 across_mid_max，三者的最大值即为最大子序和。
```cpp
class Solution {
public:
    const int MIN = -2147483648;
    int maxSubArray(vector<int>& nums) {
        return maxSubArray_divideAndConquer(nums, 0, nums.size() - 1);
    }
    int maxSubArray_divideAndConquer(const vector<int>& nums, const int start, const int end){
        if(start == end) return nums[start];
        int mid = (start + end) / 2;
        //获取左、右部分最大值
        int left_max = maxSubArray_divideAndConquer(nums, start, mid);
        int right_max = maxSubArray_divideAndConquer(nums, mid + 1, end);
        //获取中间最大值
        int left_across_mid_max = MIN;
        int left_across_mid_sum = 0;
        for( int i = mid; i >= start; i-- ){
            left_across_mid_sum += nums[i];
            left_across_mid_max = max(left_across_mid_max, left_across_mid_sum);
        }
        int right_across_mid_max = MIN;
        int right_across_mid_sum = 0;
        for( int i = mid + 1; i <= end; i++ ){
            right_across_mid_sum += nums[i];
            right_across_mid_max = max(right_across_mid_max, right_across_mid_sum);
        }
        int across_mid_max = left_across_mid_max + right_across_mid_max;
        return max(left_max, max(right_max, across_mid_max));
    }
};
```

#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
在线处理法|O(1)|O(n)
分治法|O(n)|O(nlogn)
#### 3.1.3 难点分析
1. 在线处理法需要理解如果当前累加的和 this_sum < 0，那么其肯定不会使得后续的子序和更大；
2. 分治法需要考虑三种可能的最大子列和情况

### 3.2 拓展
本题可以有很多变形，可以尝试[最小子序列和](https://blog.csdn.net/u011493189/article/details/52409375)。
