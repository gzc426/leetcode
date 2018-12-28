```java
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int len = flowerbed.length;
        if (len < 2 * n - 1) {
            return false;
        }
        for (int i = 0; i < len && n > 0; ) {
            int next = i + 1 < len ? flowerbed[i + 1] : 0;
            if (flowerbed[i] == 0 && next == 0) {
                --n;
                i += 2;
            } else {
                while (++i < len && flowerbed[i] == 1) {}
                ++i;
            }
        }
        return n == 0;
    }
}
```
