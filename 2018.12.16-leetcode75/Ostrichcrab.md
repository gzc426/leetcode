```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int blue = nums.size()-1;
        for(int i = 0; i <= blue; i++)
        {
            if(nums[i] == 0){
                int tmp = nums[i];
                nums[i] = nums[red];
                nums[red] = tmp;
                red++;
            }
            else if(nums[i] == 2){
                int tmp = nums[i];
                nums[i] = nums[blue];
                nums[blue] = tmp;
                blue--;
                i--;
            }
        }
    }
};
```
