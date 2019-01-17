```java
    List<List<Integer>> res = new ArrayList<List<Integer>>();

    public List<List<Integer>> permuteUnique(int[] nums) {

        int len = nums.length;
        if (len==0) return res;
        huisu(0,len,nums);
        return res;
    }

    public void huisu(int deep, int len, int[] nums){

        if (deep==len-1){
            List<Integer> tempList = new ArrayList<>();
            for (int i=0;i<len;i++){
                tempList.add(nums[i]);
            }
            res.add(tempList);
            return;
        }
        Set set = new HashSet();
        //set.add(nums[deep]);
        for (int i=deep;i<len;i++){
            if (set.add(nums[i])) {
                swap(deep,i,nums);
                huisu(deep+1,len,nums);
                swap(deep,i,nums);
            }
        }
        set.clear();
    }

    public void swap(int i, int j, int[] nums){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
```
