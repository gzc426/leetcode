class Solution {
    public int maxArea(int[] height) {
        int start = 0;
        int end = height.length-1;
        int tempHeight = 0;
        int temp = 0;
        int result = 0;
        while (start < end){
            int ju = end-start;
            if (height[start] > height[end]){
                tempHeight = height[end];
                temp = ju*tempHeight;
                end--;
            }else{
                tempHeight = height[start];
                temp = ju*tempHeight;
                start++;
            }
            if (result < temp){
                result = temp;
            }
        }
        return result;
    }
}
