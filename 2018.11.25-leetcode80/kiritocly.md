package com.zhongan.leetcode练习;

import java.util.Scanner;

/**
 * @author chenliyang
 * @description 删除排序数组中的重复项
 * 每一个数最多出现两次
 * @date 2018/11/25
 */
public class Leetcode80 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        System.out.println(solution(nums));
    }

    private static int solution(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        if (nums.length == 1) {
            return 1;
        }
        if (nums.length == 2) {
            return 2;
        }
        //定义两个指针，一个用于指示（1）当前判断的重复元素的第三个重复或者最后一个重复位置的下一个位置（2）当前判断元素不重复，
        // 另一个用于指示重复元素后面一个元素的位置
        //以1 1 1 2 2 3为例
        int curLast = 0;
        int curLastNext = curLast;
        int tempCount = 0;
        int resultCount = 0;
        while (curLastNext < nums.length) {
            //从头开始遍历每一个元素出现的次数
            if (curLastNext < nums.length && nums[curLastNext] == nums[curLast]) {
                curLastNext++;
                //统计当前元素出现的次数
                tempCount++;
            } else {
                //某个重复元素的个数统计完成，需要完成两件事
                //（1）统计一次最终得到的数组的长度
                //（2）移动指针，比如第一次循环到达这个else循环应该将curLast移动到第三个1的位置，
                // curLast指向1，此时curLastNext指向2
                if (tempCount >= 2) {
                    //完成（1）,重复两次或以上的元素，长度记两次
                    resultCount += 2;
                    //元素重复两次
                    nums[curLast + 1] = nums[curLast];
                    //完成（2），重复两次或以上的元素全部移动到第三个重复位置
                    curLast += 2;
                } else {
                    //完成（1），元素未重复，长度记一次
                    resultCount++;
                    //完成（2），移动一位
                    curLast++;
                }
                if (curLastNext >= nums.length) {
                    break;
                }
                //修改元素
                nums[curLast] = nums[curLastNext];
                tempCount = 0;
            }
        }
        //输出前resultCount个元素
        //比如1 1 1 2 2 3变成1 1 2 2 3 3,取前五个元素
        return resultCount;
    }
}
