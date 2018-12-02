```
#include <iostream>
#include <vector>
using namespace std;

//mysol:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1])
            nums.erase(nums.begin() + i);
        }
        return nums.size();
    }
//better sol:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
```
