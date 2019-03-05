# leetcode 39
    class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
         List<List<Integer>> res = new ArrayList<>();
        if (candidates == null || candidates.length == 0 || target <= 0) {
            return res;
        }
        Arrays.sort(candidates);
        combination(res,candidates,new ArrayList<Integer>(),target,0,candidates.length);
        return res;
    }
    private static void combination(List<List<Integer>> res,int [] arr, ArrayList<Integer> list,
                                    int target, int index, int length) {
        if (target == 0) {
            ArrayList<Integer> temp=new ArrayList<>(list);
            Collections.sort(temp);
            if (!res.contains(temp)) {
                res.add(new ArrayList<Integer>(temp));
            }
            return;
        }
        if (index >= length) {
            return;
        }
        for (int i = index; i<length&&arr[i]<=target ; i++) {
                list.add(arr[i]);
                combination(res, arr, list, target - arr[i], index, length);
                list.remove(list.size() - 1);
        }

    }
}
