leetcode of 215
```
class Solution {
public:
    int partition(vector<int>& nums,int k, int s, int t){
        int i = s - 1;
        for(int j = s; j < t; j++){
            if(nums[j] > nums[t]){
                i++;
                swap(nums[j],nums[i]);
            }
        }
        i++;
        swap(nums[i],nums[t]);
        return i;
    }
    int find(vector<int>& nums,int k, int s,int t){
        int q = partition(nums,k,s,t);
        if(q == k - 1) return nums[k-1];
        else if(q < k - 1){
            return find(nums,k,q+1,t);
        }else{
            return find(nums,k,s,q-1);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        return find(nums,k,0,nums.size()-1);
    }
};
```
