# LeetCode 605
    class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {//对每个位置为0的元素，考虑元素相邻位置是不是都为0，如果为0符合条件，如果不为0跳过该位置考虑下一个位置，两端单独考虑。
        if (flowerbed == null || flowerbed.length == 0||n<0) {
            return false;
        }
        if (n == 0) {
            return true;
        }
        if (n == 1 && flowerbed.length == 1 && flowerbed[0] == 0) {
            return true;
        }
        if (flowerbed[0] == 0 && flowerbed.length > 1 && flowerbed[1] == 0) {
            flowerbed[0]=1;
            n--;
        }
        for (int i = 1; i < flowerbed.length-1; i++) {
            if (n == 0) {
                break;
            }
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i]=1;
                n--;
            }
        }
        if (n!=0&&flowerbed.length > 1 && flowerbed[flowerbed.length - 1] == 0 && flowerbed[flowerbed.length - 2] == 0) {
            n--;
        }
        return n==0;
    }
}
