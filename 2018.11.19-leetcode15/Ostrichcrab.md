```

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());   //排序，从小到大
        for(int i = 0 ; i < n - 2; i ++){
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] > 0){
                     k --; 
                 }
                 else if(nums[i] + nums[j] + nums[k] < 0){
                     j ++;
                 }
                 else{
                     ans.push_back({nums[i], nums[j], nums[k]});
                     while(nums[j+1] == nums[j])   j++;
                     j ++;
                 }
            }
            while(nums[i+1] == nums[i])   i++;
        }
    
        return ans;
    }
};

```
