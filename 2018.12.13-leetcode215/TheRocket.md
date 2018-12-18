```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        k = nums.length - k;
        return quickSelect(nums, k);
    }

    private int quickSelect(int[] nums, int k) {
        int lo = 0;
        int hi = nums.length - 1;
        while (lo < hi) {
            int i = partition(nums, lo, hi);
            if (i < k) {
                lo = i + 1;
            } else if (i > k) {
                hi = i - 1;
            } else {
                return nums[i];
            }
        }
        return nums[lo];
    }

    private int partition(int[] nums, int lo, int hi) {
        int m = median3(nums, lo, lo + (hi - lo) / 2, hi);
        swap(nums, lo, m);
        int i = lo;
        int j = hi + 1;
        int v = nums[lo];
        while (true) {
            while (nums[++i] < v && i < hi) {}
            while (nums[--j] > v) {}
            if (i >= j) {
                break;
            }
            swap(nums, i, j);
        }
        swap(nums, lo, j);
        return j;
    }

    private static int median3(int[] nums, int i, int j, int k) {
        return nums[i] < nums[j] ?
                (nums[j] < nums[k] ? j : nums[i] < nums[k] ? k : i) :
                (nums[k] < nums[j] ? j : nums[k] < nums[i] ? k : i);
    }

    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
```
