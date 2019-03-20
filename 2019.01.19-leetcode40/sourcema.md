# leetcode 40
    class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
         List<List<Integer>> res = new ArrayList<>();
        if (candidates == null || candidates.length == 0 || target <= 0) {
            return res;
        }
        Arrays.sort(candidates);//
        combination(res,candidates,new ArrayList<Integer>(),target,0);
        return res;
    }
    private static void combination(List<List<Integer>> res, int[] candidates, ArrayList<Integer> list,
                                    int target, int index) {
        if (target == 0) {
            if (!res.contains(list))
            res.add(new ArrayList<Integer>(list));
            return;
        }
        if (index>=candidates.length||target < candidates[index]) {
            return;
        }
            list.add(candidates[index]);
            combination(res,candidates,list,target-candidates[index],index+1);
            list.remove(list.size() - 1);
            combination(res,candidates,list,target,index+1);
    }
}
