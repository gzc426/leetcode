# LeetCode 215
    class Solution {
    public int findKthLargest(int[] nums, int k) {
        int left=0;
        int right=nums.length-1;
        int index = partition(nums, left, right);
        k=nums.length-k+1;//5个数，第二大就是比他小的数有三个，这个数就是第四小的数
        while (index != k - 1) {
            if (index < k - 1) {
                left=index+1;
                index = partition(nums, left, right);
            } else {
                right=index-1;
                index = partition(nums, left, right);
            }
        }
        return nums[index];
    }
    public  int partition(int[] arr,int left,int right) {
        int pivot=arr[left];
    //      int left=start;
    //      int right=end;
        int pivotPointer=left;
        while (left < right) {
            while (left<right&&arr[right] >= pivot) {
                right--;
            }
    //            swap(arr, left++, right);
            while (left<right&&arr[left] <= pivot) {
                left++;
            }
            swap(arr, left, right);
        }
        swap(arr,pivotPointer,left);
    //        System.out.println(Arrays.toString(arr));
        return left;
    }
     public    void swap(int [] arr,int i,int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j]=temp;
    }
}
