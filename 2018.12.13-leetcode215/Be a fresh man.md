## 215_(数组中的第K个最大元素)Kth Largest Element in a Array
## 1 问题描述、输入输出与样例
### 1.1 问题描述
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。<br>
__说明__:<br>
你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
### 1.2 输入与输出
输入：
* vector<int>& nums:给定未排序的数组的引用
* int k:第 k 个最大的元素

输出：
* int:数组排序后的第 k 个最大的元素
### 1.3 样例
#### 1.3.1 样例1
输入: [3,2,1,5,6,4] 和 k = 2<br>
输出: 5<br>
#### 1.3.2 样例2
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4<br>
输出: 4<br>
## 2 思路描述与代码	
### 2.1 思路描述（快排partition+递归方法）
1. 首先介绍下什么叫做快排partition（以从大到小排序为例）：<br>
其目的就是根据第一个值 val 把数组分割成大于第一个值的左半部分与小于第一个值的右边部分，然后再把第一个值与左半部分的最后一个值交换，并返回第一个值交换后的下标,使用的方法就是双边扫描:
```cpp
val = nums[start];
i = start + 1;
j = end;
while( i <= j ){
    //i <= j 防止越界
    if(i <= j) i 从左向右扫描直至找到 nums[i] < val;
    if(i <= j) j 从右向左扫描直至找到 nums[j] > val;
    //每一次交换消去了很多逆序对了，所以快速排序很快。
    if(i < j) swap(nums[i], nums[j]);
    else break;
}
//交换完毕后，此时的 j 的位置就是大于第一个值的左半部分的最后一个数据
swap(nums[start], nums[j]);
return j;
```
比如数组nums[3,2,1,5,6,4]，以3为参考点<br>
i = 1, j = 5, i <= j 成立，第1次交换发生在i = 1, j = 5的时候，此时满足 i < j，交换后为i = 2, j = 4, nums = [3,4,1,5,6,2]<br>
i = 2, j = 4, i <= j 成立，第2次交换发生在i = 2, j = 4的时候，此时满足 i < j，交换后为i = 3, j = 3, nums = [3,4,6,5,1,2]<br>
i = 3, j = 3, i <= j 成立, 不满足交换条件，跳出循环;<br>
此时 j = 3 是大于第一个值的左半部分的最后一个数据，交换 nums[0] 和 nums[3] , nums = [5,4,6, 3, 1,2]<br>
返回 此时的 j 的下标 3。

2. 有了快排partition返回的下标idx(这意味着nums[idx]是第idx + 1大的元素)，我们就很容易想到利用其来找数组中的第K个最大元素，
判断准则如下:
* if(pos == k - 1) 则找到了第 k 大的值;
* else if(pos < k - 1) 则第 k - 1个大的值在 nums[idx]的左边，则往左递归快排partition即可;
* else 则第 k - 1个大的值在 nums[idx]的右边，则往右递归快排partition即可;

3. 这边举个例子比如输入数组nums[3,2,1,5,6,4]，k = 2；<br>
第1次快排partition后, 数组nums = [5,4,6, 3, 1,2],返回下标是3, 意味着 nums[3] = 3 是第 4(3 + 1)大的元素，那么第二大的元素肯定是在左边,于是递归快排partition数组nums的前3个元素[5,4,6];<br>
第2次快排partition后, 数组nums = [4,5,6, 3,1,2],返回下标1, 意味着 nums[1] = 5 是第 2(1 + 1)大的元素，于是返回5。<br>


### 2.2 代码
```cpp
//函数中涉及到的c++知识
//vector<int> 是个长度可变的int数组，c++里面成为容器
//ret_func_type func(vector<int>& name) 中的name是vector<int>容器的引用，可以理解为传入一个指针
//vector<int>::iterator 是c++中的迭代器，可以理解为一个长度可变的int数组的指针类型



//快排中的一个partition步骤
//以val = nums[end]为参考点，分离成 比首元素大的节点 + val + 比首元素小的节点
//返回 val 最后所在的下标
int partition(vector<int>& nums, int start, int end){
    int i = start + 1;
    int j = end;
    while( i <= j ){
        while( i <= j && nums[i] > nums[start] ) i++;
        while( i <= j && nums[j] < nums[start] ) j--;
        if(i < j) swap(nums[i++], nums[j--]);
        else break;
    }
    swap(nums[start], nums[j]);
    return j;
}
//基于快排partition的查找第K个最大元素的方法
int qsort_partition_findKthLargest(vector<int>& nums, int start, int end, int k){
    int pos = partition(nums, start, end);
    //如果恰好是第 k - 1 个元素
    if(pos == k - 1) return nums[pos];
    //如果返回的位置比要求的位置大，则说明需要去左边找
    else if(pos > k - 1) return qsort_partition_findKthLargest(nums, start, pos - 1, k);
    //如果返回的位置比要求的位置小，则说明需要去右边找
    else return qsort_partition_findKthLargest(nums, pos + 1, end, k);
}


int findKthLargest(vector<int>& nums, int k) {
    //基于快排partition的查找第K个最大元素的方法
    return qsort_partition_findKthLargest(nums, 0, nums.size() - 1, k);
}
```
## 3 思考与拓展
### 3.1 思考
本题如果了解快排partition的话，则问题很容易可以解决，partition原理也不难。
#### 3.1.1 其他方法
#### 3.1.1.1 快排partition+尾递归
本题可以修改为尾递归的形式，有兴趣的可以尝试一下。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
快排partition+递归|O(logn)|O(nlogn)
快排partition+尾递归|O(1)|O(nlogn)
#### 3.1.3 难点分析
1. 快排partition的边界考虑
2. 基于快排partition的递归规则

### 3.2 拓展
如果给你的是链表数据呢？
