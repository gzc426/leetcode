```java
    public List<List<Integer>> subsets(int[] nums) {

        List<List<Integer>> res = new ArrayList<>();
        if (nums==null||nums.length==0) return res;
        List<Integer> box = new ArrayList<>();
        List<Integer> allList = new ArrayList<>();

        search(0,nums.length,nums,box,allList,res);

        return res;
    }

    public void search(int startNum, int endNum, int[] nums, List<Integer> box, List<Integer> allList, List<List<Integer>> res){

        if (startNum==0) {
            res.add(new ArrayList<>());
            startNum++;
        }
        if (endNum==nums.length) {
            for (int i : nums){
                allList.add(i);
            }
            res.add(allList);
            endNum--;
        }
        if (startNum==endNum){
            digui(startNum, 0, nums, box, allList, res, true);
            return;
        }
        if (startNum>endNum){
            return;
        }

        digui(startNum, 0, nums, box, allList, res, false);

        search(startNum+1,endNum-1,nums,box,allList,res);

    }

    public void digui(int k, int index, int[] nums, List<Integer> box, List<Integer> allList, List<List<Integer>> res, boolean isEqual){
        if (k==0) {
            res.add(new ArrayList<>(box));
            if (isEqual) return;
            ArrayList<Integer> tempList = new ArrayList<>(allList);
            if(tempList.removeAll(box)) {
                res.add(tempList);
            }
            return;
        }

        for (int i=index;i<nums.length;i++){
            box.add(nums[i]);
            digui(k-1,i+1,nums,box,allList,res,isEqual);
            box.remove(box.size()-1);
        }
    }
```
