```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=-1;
        int end=nums.size();
        int index=0;
        while(index<end)
        {
            if(nums[index]<1)
                swap(nums[++start],nums[index++]);
            else if(nums[index]>1)
                swap(nums[--end],nums[index]);
            else 
                index++;
        }
        
    }
};
```
