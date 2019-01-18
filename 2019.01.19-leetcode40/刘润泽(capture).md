```java
   public void search(int[] candidates, int target, List<Integer> box, List<List<Integer>> res, int n, boolean flag) {

        if (target==0){
            res.add(new ArrayList<Integer>(box));
        }

        if(n == candidates.length || target < candidates[n])
            return;

        if (flag&&n>0&&n<candidates.length&&candidates[n]==candidates[n-1]) {
            search(candidates, target, box, res, n + 1, true);
            return;
        }

        search(candidates, target, box, res, n + 1, true);
        box.add(candidates[n]);
        search(candidates,target - candidates[n],box,res,n+1, false);
        box.remove(box.size()-1);

    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        if(candidates == null || candidates.length == 0) {
            return res;
        }
        Arrays.sort(candidates);
        List<Integer> box = new ArrayList<>();
        search(candidates, target, box, res, 0, true);
        return res;
    }
```
