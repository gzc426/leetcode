```java
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        if (A == null || A.length < 3) {
            return 0;
        }
        int res = 0;
        int cur = 0;
        for (int i = 2; i < A.length; ++i) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                res += ++cur;
            } else {
                cur = 0;
            }
        }
        return res;
    }
}
```
