```java
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int lo = 0;
        int hi = letters.length;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (target >= letters[mid]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo == letters.length ? letters[0] : letters[lo];
    }
}
```
