# LeetCode 69
    class Solution {
    public int mySqrt(int n) {
         if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        int left=0;
        int right=n;
        while (left<=right) {
            int mid=(left+right)/2;
            if (mid < n/mid) {
                left=mid+1;
            } else if (mid> n/mid) {
                right=mid-1;
            } else {
                return mid;
            }
        }
        return left-1;
    }
}
