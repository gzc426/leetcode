```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int cnt = 0;
        int pre = -1;
        int len = nums.size();
        pre = nums[0];
        cnt = 1;
        for(int i = 1; i < len; i++)
        {
            if(nums[i]==pre)
            {
                cnt++;
                if(cnt==3) 
                {
                    nums.erase(nums.begin()+i);
                    cnt--;
                    len--;
                    i--;
                }
            }
            else
            {
                cnt=1;
                pre=nums[i];
            }
        }
        return nums.size();
    }
};
```
