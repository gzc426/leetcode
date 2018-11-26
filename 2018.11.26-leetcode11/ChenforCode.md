/**
 * @author: ChenforCode
 * @date: 2018/11/26 15:03
 * @description: 给定几个线段，求两条线段和x轴组成的容器的面积最大值
 * 当两边线段移动的时候，距离（底是变小的），所以必须想办法提高高度，
 * 而面积是取决于那个最短的线段，所以移动短的线段，才有可能的到最好的解
 */
public class Solution {
    /*public static void main(String[] args) {
        int[] a = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        System.out.println(maxArea(a));
    }*/

    public static int maxArea(int[] height) {
        int i = 0, j = height.length - 1, maxArea = -1;
        while (i < j) {
            int area = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
            if (area > maxArea) {
                maxArea = area;
            }
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxArea;
    }
}
