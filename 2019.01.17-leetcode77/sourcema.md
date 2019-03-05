# leetcode 77
    class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        dfs(n, k, res, list, 1);
        return res;
    }
    public void dfs(int n, int k, List<List<Integer>> res, List<Integer> list, int start){
        if(list.size() == k){
            res.add(new ArrayList(list));
            return;
        }
        for(int i = start; i <= n; i++){
            list.add(i);
            dfs(n, k, res, list, i + 1);
            list.remove(list.size() - 1);
        }
    }
}
