```
public class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> result=new ArrayList<>();
        List<Integer> list=new ArrayList<>();
        Arrays.sort(nums);
        backtracking(result, nums, list, 0);
        return result;
    }
     
    public void backtracking(List<List<Integer>> result,int nums[],List<Integer> list,int start) {
        result.add(new ArrayList<>(list));
        for(int i=start;i<nums.length;i++){
            if(i>start&&nums[i]==nums[i-1]) continue;　　　　//跳过重复的
            list.add(nums[i]);
            backtracking(result, nums, list, i+1);
            list.remove(list.size()-1);
             
        }
    }
}

```
