/*
  题目：
  给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
 
  做法：
  遍历一趟，记录每个元素出现的次数，生成一个unordered_map。
  遍历这个unordered_map，把其元素放入priority_queue(这是一个队列，且队列首元素一直都是最大的)。
  
  参考：
  https://blog.csdn.net/a2331046/article/details/52445088
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        for(int i=0; i<nums.size(); i++){
            um[nums[i]]++;
        }
        
        priority_queue<pair<int,int>> pq;
        for(auto it:um){
            pq.push( make_pair(it.second,it.first) );
        }
        
        vector<int> rst;
        for(int i=0; i<k; i++){
            rst.push_back(pq.top().second);
            pq.pop();
        }
        
        return rst;
    }
};
