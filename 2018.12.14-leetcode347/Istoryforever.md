leetcode of 347. Top K Frequent Elements
```
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto i : nums){
            if(m.count(i) == 0){
                m[i] = 1;
            }else{
                ++m[i];
            }
        }
        //两种方式，一种是partition，另一种是最小堆
        vector<int> ans;
        vector<int> ans_index;
        for(auto i = m.begin(); i != m.end(); ++i){
            ans.push_back(i->second);
            ans_index.push_back(i->first);
        }
        sort(ans_index.begin(),ans_index.end(),[&m](int a,int b){
            return m[a] > m[b];
        });
        ans_index.erase(ans_index.begin()+k,ans_index.end());
        return ans_index;
    }
};
```
