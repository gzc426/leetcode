```java
    public List<List<Integer>> combinationSum(int[] candidates, int target) {

        List<List<Integer>> res = new ArrayList<>();
        List<Integer> box = new ArrayList<>();
        Arrays.sort(candidates);

        for (int i=0;i<candidates.length;i++){
            huisu(0,target,i,candidates,new ArrayList<Integer>(),res);
        }

        return res;
    }

    public void huisu(int currSum, int target, int index, int[] candidates, List<Integer> box, List<List<Integer>> res){

        if (index==candidates.length)return;
        int count = 0;
        while (currSum<target){
            currSum += candidates[index];
            if (currSum>target) break;
            box.add(candidates[index]);
            count++;
            if (currSum==target){
                res.add(new ArrayList<Integer>(box));
                break;
            }
            for (int i=index+1;i<candidates.length;i++){
                huisu(currSum,target,i,candidates,box,res);
            }
        }
        for (int i=0;i<count;i++){
            box.remove(box.size()-1);
        }
    }
```
