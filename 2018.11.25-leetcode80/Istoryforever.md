leetcode number 80
```
class Solution {
public:
    void swap(int &a,int &b){
        int c = a;
        a = b;
        b = a;
        
    }
    int removeDuplicates(vector<int>& nums) {
        int j = -1;
        int count = 0;
        for(int i = 0;i < nums.size();i++){
            if(i != 0 && nums[i] == nums[i-1])   {
                if(count >= 1) continue;
                ++count;
            }
            else
                count = 0;
            nums[++j]=nums[i];
        }
        return j+1;
        
    }
};
```
