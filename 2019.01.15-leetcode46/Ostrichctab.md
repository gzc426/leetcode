```
class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>> &res, vector<int> t, vector<int> &flag)
    {
        if(t.size()==nums.size()) {
            res.push_back(t);
            return ;
        }
        for(int i = 0; i<nums.size(); i++)
        {
            if(flag[i]==1) continue;
            t.push_back(nums[i]);
            flag[i]=1;
            dfs(nums,res,t,flag);
            t.pop_back();
            flag[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> t;
        vector<int> flag(nums.size(),0);
        if(nums.size()==0) return res;
        dfs(nums,res,t,flag);
        return res;
    }
};
```
