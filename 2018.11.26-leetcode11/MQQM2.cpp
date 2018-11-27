//24ms
/*
  题目：
  给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai)。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
  找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
  
  说明：你不能倾斜容器，且 n 的值至少为 2。
  
  参考：
  https://blog.csdn.net/m0_37402140/article/details/80370794
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=0;
        
        int i=0, j=height.size()-1;        
        while(i<j){
            if(height[i]>height[j]){
                max_area = max(max_area, height[j]*(j-i));                    
                j--;                
            }else{
                max_area = max(max_area, height[i]*(j-i));
                i++;
            }
        }
   
        return max_area;
    }
};
