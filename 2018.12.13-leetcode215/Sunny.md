```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return -1;
        }
        List<Integer> sorted = new ArrayList<>();
        for (int i=0; i<nums.length; i++) {
            sorted.add(nums[i]);
        }
        // List<Integer> sorted = Arrays.stream(nums).boxed().collect(Collectors.toList());
        sorted.sort((a,b) -> b-a);
        return sorted.get(k-1);
    }
}
```
