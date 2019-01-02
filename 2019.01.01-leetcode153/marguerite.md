
```
class Solution {
public:
    int findMin(vector<int> &num) {
        int start = 0;
        int end = num.size() - 1;
        int mid = 0;
        while (start < end) { //注意这里和普通的二分查找不同，这里是start < end不是 start <= end.
                mid = start + (end - start)/2;
                if (num[mid] > num[end])
                    start = mid + 1; //此时可以扔掉mid的值
                else 
                    end = mid;//此时不能扔掉mid的值
        }
        return num[end]; //退出循环说明start与end相等，所以只剩一个元素可能，所以return [start]或者return [end]都可以了。
        //注意不能return mid，可以从{2,1}这个输入看出来。
        
    }
    
 ```

