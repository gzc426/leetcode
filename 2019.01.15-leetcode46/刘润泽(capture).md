```java
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> currRes = new ArrayList<>();
        fenzhi(nums,0,currRes,res);
        return res;
    }

    public void fenzhi(int[] nums, int deep, List<Integer> currRes, List<List<Integer>> res){
        if (nums.length==1){
            currRes.add(nums[0]);
            List<Integer> tempRes = new ArrayList<>();
            for (int i=0;i<currRes.size();i++){
                tempRes.add(currRes.get(i));
            }
            res.add(tempRes);
            tempRes=null;
            return;
        }
        for (int i=0;i<nums.length;i++){
            while (currRes.size()!=0&&currRes.size()>deep){
                currRes.remove(currRes.size()-1);
            }
            int[] nextNums = new int[nums.length-1];
            for (int j=0,k=0;j<nextNums.length;j++,k++){
                if (j==i){
                    k++;
                }
                nextNums[j]=nums[k];
            }
            currRes.add(nums[i]);

            fenzhi(nextNums,deep+1,currRes,res);
        }
    }
```
