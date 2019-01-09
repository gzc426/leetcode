## 121_(买卖股票的最佳时机)Best Time to Buy and Sell Stock
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。<br>
如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。<br>
注意你不能在买入股票前卖出股票。
### 1.2 输入与输出
输入：
* vector<int>& prices:长度可变的价格数组prices

输出：
* int:所能获取的最大利润
### 1.3 样例
#### 1.3.1 样例1
输入: [7,1,5,3,6,4]<br>
输出: 5<br>
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
#### 1.3.2 样例2
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
## 2 思路描述与代码	
### 2.1 思路描述（动态规划法）
dp[i] 表示为第 i + 1 天可获得的最大利润;
此时最大利润可能是下述两种情况：
1. 当前卖出的的情况是prices[i]-最低价
2. 不是当天卖出的情况是dp[i-1]
于是dp[i] = max(prices[i]-最低价, dp[i-1]);<br>
dp中只与前一个元素有关，可以写成简化空间复杂度的写法:max_profit = max(prices[i]-最低价, max_profit)。

比如输入: [7,1,5,3,6,4];<br>
i = 0, min_price = 7, dp[0] = 0;<br>
i = 1, min_price = 1, dp[1] = min(0, 0) = 0;<br>
i = 2, min_price = 1, dp[2] = min(5 - 1, 0) = 4;<br>
i = 3, min_price = 1, dp[3] = min(3 - 1, 4) = 4;<br>
i = 4, min_price = 1, dp[4] = min(6 - 1, 4) = 5;<br>
i = 5, min_price = 1, dp[5] = min(4 - 1, 5) = 5;<br>
### 2.2 代码
```cpp
//函数中涉及到的c++知识
//vector<int> 是个长度可变的 int 数组，c++里面称为容器
int maxProfit(vector<int>& prices) {
    int len = prices.size();
    //边界情况
    if(len == 0) return 0;
    
    //当前最大的利益 = max(前一天可能的最大利益, 今天的价钱-最低价)
    int max_profit = -2147483648;
    int min_price = 2147483647;
    for( int i = 0; i < prices.size(); i++ ){
        min_price = min(min_price, prices[i]);
        max_profit = max(max_profit, prices[i] - min_price);
    }
    return max_profit;
}
```
## 3 思考与拓展
### 3.1 思考
本题通过分析在第 x 天可能卖出的最大收益的情况可以很快推出动态规划的递推表达式，然后再做空间的简化即可。
#### 3.1.1 其他方法
#### 3.1.1.1 差分+最大连续子列和
1. 先求差分数组
2. 求差分数组中的最大连续子列和

#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
动态规划法|O(1)|O(n)
差分+最大连续子列和|O(n)|O(n)
#### 3.1.3 难点分析
1. 求递归表达式
2. 简化空间复杂度

### 3.2 拓展
1. [买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)。
