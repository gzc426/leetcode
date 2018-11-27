leetcode of 15
```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       
        vector<vector<int>> res;
        if(nums.size()==0) return res;
        sort(nums.begin(),nums.end());
        int i=0;
        int p=0;
        int q=0;
        while(i<nums.size()-2){
            if(i>0 &&nums[i-1]==nums[i]){
                i++;
                continue;
            }
            if(nums[i]>0) break;
           int  diff=0-nums[i];
            p=i+1;
            q=nums.size()-1;
            while(p<q){
                if(nums[p]+nums[q]<diff && p<q) p++;
                if(nums[p]+nums[q]>diff && p<q) q--;
                else if(p<q && nums[p]+nums[q]==diff){
                   vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[p]);
                    temp.push_back(nums[q]);
                    res.push_back(temp);
                    p++;
                    q--;
                    while(p<q &&nums[p]==nums[p-1]){
                        p++;
                    }
                    while(p<q &&nums[q]==nums[q+1]){
                        q--;
                    }
                }
            }
            i++;
        }
        return res;
    }
};
```
