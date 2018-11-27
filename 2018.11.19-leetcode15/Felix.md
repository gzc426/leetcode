```
import java.util.Arrays;

/**
 * @author Felix
 * @date 2018年11月2日下午7:27:55
   @version 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。
   返回这三个数的和。假定每组输入只存在唯一答案。例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 */
public class ThreeSumClosest {
	public int threeSumClosest(int[] nums,int target){
		int res = nums[0] + nums[1] +nums[nums.length-1];
		Arrays.sort(nums);//将数组排序
		for(int first=0; first<nums.length-2; first++){//从0开始固定第一个数，第二三个数分别为剩下的边界
			int second = first+1,third = nums.length-1;
			while(second < third){
				int sum = nums[first] + nums[second] + nums[third];
				if(sum < target){//数组已经从小到大排序，若sum<target，则第二个数向右走，相当于让sum值变大，更接近target
					second++;
				}else if(sum > target){//若小于则第三个数向左走，相当于让sum值变小，更接近target
					third--;
				}else{//相等则最接近target，直接返回
					return sum;
				}
				res = Math.abs(sum-target)<Math.abs(res-target) ? sum : res;
			}
		}
		return res;
	}
}
```
