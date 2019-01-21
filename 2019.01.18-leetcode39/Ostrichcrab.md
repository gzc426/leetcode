```
class Solution {
public:
    void dfs(vector<int> candidates, int start, int target, vector<int> item, vector<vector<int>>& res)
    {
        if(target<0) return;
        if(target==0) {
            res.push_back(item);
            return ;
        }
        for(int i = start; i < candidates.size(); i++){
            item.push_back(candidates[i]);
            dfs(candidates,i,target-candidates[i],item,res);
            item.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> item;
        dfs(candidates,0,target,item,res);
        return res;
    }
};
```
