//748ms
/*
  题目：
  给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai)。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
  找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

  说明：你不能倾斜容器，且 n 的值至少为 2。
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=0;
        
        for(int i=0; i<=height.size()-2; i++){
            for(int j=i+1; j<=height.size()-1; j++){
                int cur_area=(j-i)*min(height[i], height[j]);
                if(cur_area>max_area){
                    max_area=cur_area;
                }
            }
        }
        
        return max_area;
    }
};
