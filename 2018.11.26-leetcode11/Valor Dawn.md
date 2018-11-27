 class Solution {

  public int maxArea(int[] height) {
      
      int left = 0;
      int right = height.length - 1;
      int result = 0;
      int tempHeight = 0;int tempResult = 0;
      
      while(left < right){
          int cha = right - left ;
          
          if(height[left] > height[right]){
            tempHeight = height[right];
            tempResult = tempHeight * cha;
            right--;
          }else{
              tempHeight = height[left];
              tempResult = tempHeight * cha;
              left++;
          }
          if(tempResult > result){
              result = tempResult;               
          }
           return result;
      }
  }
 }
