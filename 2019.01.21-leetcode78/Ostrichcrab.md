```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int m = 1<<n;
        vector<vector<int>> res(m,vector<int>());
        for(int i = 0; i < n; i++)
            for(int j =  0; j < m; j++)
                if((j>>i)&1)
                    res[j].push_back(nums[i]);
        return res;
    }
};
```
