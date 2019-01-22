```java
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(nums, res, 0);
        return res;
    }

    private void dfs(int[] nums, List<List<Integer>> res, int s) {
        if (s == nums.length) {
            List<Integer> list = new ArrayList<>(nums.length);
            for (int num : nums) {
                list.add(num);
            }
            res.add(list);
            return;
        }
        for (int i = s; i < nums.length; ++i) {
            if (isDuplicate(nums, s, i)) {
                continue;
            }
            swap(nums, i, s);
            dfs(nums, res, s + 1);
            swap(nums, i, s);
        }
    }

    private boolean isDuplicate(int[] nums, int s, int e) {
        for (int i = s; i < e; ++i) {
            if (nums[i] == nums[e]) {
                return true;
            }
        }
        return false;
    }

    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
```
