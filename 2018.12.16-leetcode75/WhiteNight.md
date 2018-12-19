```java
/**
 * 颜色分类
 */
public class S4 {
    public void sortColors(int[] nums) {  //一遍扫描算法
        int Size = nums.length;
        int i = -1, j = -1, k = -1;
        for (int l = 0; l < Size; l++) {
            if (0 == nums[l]){
                nums[++k] = 2;
                nums[++j] = 1;
                nums[++i] = 0;
            }
            else if (1 == nums[l]){
                nums[++k] = 2;
                nums[++j] = 1;
            }
            else
                nums[++k] = 2;
        }
    }

    public static void main(String[] args) {
        S4 s = new S4();
        int[] nums = {2, 0, 2, 1, 1, 0};
        s.sortColors(nums);
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
    }
}
```