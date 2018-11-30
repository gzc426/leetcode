```javascript
package leetcode.medium;
/**
 * @author Felix
 * @date 2018年10月31日下午9:59:27
   @version 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 
   (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。说明：你不能倾斜容器，且 n 的值至少为 2。
 */
public class MaxArea {
	public int maxArea(int[] height){
		int len = height.length;
		int max = 0,low = 0,high = len - 1;
		while(low < high){
			int lowMax = height[low],highMax = height[high];
			int water = (high - low) * (lowMax < highMax ? lowMax : highMax);
			max = water > max ? water : max;
			
			if(height[low] <= height[high]){
				while(low < high && height[low] <= lowMax)
					low++;
			}else{
				while(high > low && height[high] <= highMax)
					high--;
			}
		}
		
		return max;
	}
}
```
