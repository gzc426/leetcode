```
class Solution {
public:
    void dfs(vector<int>& nums, int pos, vector<int>& path, vector<vector<int>>& result){
        if(pos==nums.size()) return ;
        for(int i = pos; i < nums.size(); i++){
            path.push_back(nums[i]);
            result.push_back(path);
            dfs(nums,i+1,path,result);
            path.pop_back();
            while(nums[i]==nums[i+1]) i++;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> result;
        result.push_back(path);
        sort(nums.begin(),nums.end());
        dfs(nums,0,path,result);
        return result;
    }
};
```
