# LeetCode 75
    class Solution {
    public void sortColors(int[] arr) {//借鉴快排partition思路
         if (arr.length == 0 || arr == null) {
            return ;
        }
        int left=-1,right=arr.length,i=0;
        while (i<right) {
            if (arr[i] == 0) {
                swap(arr, ++left, i++);
            } else if (arr[i] == 2) {
                swap(arr, --right, i);
            } else {
                i++;
            }
        }
    }
    public    void swap(int [] arr,int i,int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j]=temp;
    }
}
