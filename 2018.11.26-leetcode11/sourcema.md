# leetcode 11
     public int maxArea(int[] height) {
         if (height == null || height.length == 0) {
            return 0;
        }
        int left=0,right=height.length-1,result=0;
        while (left < right) {
            result = Math.max(result, Math.min(height[left], height[right]) * (right - left));
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
