```java
  public int singleNonDuplicate(int[] nums) {
        if (nums.length==1) return nums[0];
        if (nums.length%2==0) return 0;
        int mid;
        int start=0;
        int end=nums.length-1;
        while(true){
            mid=(start+end)/2;
            if (nums[mid]==nums[mid-1]&&(mid-start)%2==1) {
                //该数一定在后面
                if ((end-start)==2) return nums[mid+1];
                start=mid+1;
            }else if (nums[mid]==nums[mid+1]&&(mid-start)%2==1) {
                //该数一定在前面
                if ((end-start)==2) return nums[mid-1];
                end=mid-1;
            }else if (nums[mid]==nums[mid-1]&&(mid-start)%2!=1) {
                //该数一定在前面
                end=mid;
            }else if (nums[mid]==nums[mid+1]&&(mid-start)%2!=1) {
                //该数一定在后面
                start=mid;
            }else {
                return nums[mid];
            }
        }
    }
```
