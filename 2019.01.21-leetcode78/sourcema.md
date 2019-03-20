# leetcode 78
    class Solution {
    public List<List<Integer>> subsets(int[] nums) {
         List<List<Integer>> res = new ArrayList<>();
        if (nums == null || nums.length == 0) {
            return res;
        }
        find(res,new ArrayList<Integer>(), nums,0);
        res.add(new ArrayList<Integer>());//add empty set
        return res;
    }
     private  void find(List<List<Integer>> res, ArrayList<Integer> list, int[] nums,int index) {
        if (index >= nums.length) {
            return;
        }
        for (int i = index; i < nums.length; i++) {
            list.add(nums[i]);
            res.add(new ArrayList<Integer>(list));
            find(res,list,nums,i+1);
            list.remove(list.size() - 1);
        }
    }
}
