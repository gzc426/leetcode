# leetcode 216
    class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
         List<List<Integer>> res = new ArrayList<>();
        if (k <= 0 || n <= 0) {
            return res;
        }
        find(res, new ArrayList<Integer>(), k, n,1);
        return res;
    }
    private static void find(List<List<Integer>> res, ArrayList<Integer> list, int k, int n,int num) {
        if (list.size() == k && n == 0) {
            res.add(new ArrayList<Integer>(list));
            return;
        }
        if (list.size() >= k) {
            return;
        }
        for (int i = num; i <=9&&i<=n ; i++) {
            list.add(i);
            find(res,list,k,n-i,i+1);
            list.remove(list.size() - 1);
        }
    }
}
