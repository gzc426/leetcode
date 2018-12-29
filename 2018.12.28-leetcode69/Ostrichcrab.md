```
class Solution {
public:
    int mySqrt(int x) {
        return sqrt(x);
    }
};
--------------------------------------
class Solution {
public:
    int mySqrt(int x) {
       double pre = 0;
        double cur = x;
        while(abs(cur-pre)>0.000001){
            pre = cur;
            cur = (pre/2+x/(2*pre));
        }
        return int(cur);
    }
};
-----------------------------------------

class Solution
{
public:
	int mySqrt(int x)
	{
		//数学大神根据牛顿迭代法来求推导出的神奇方法
		assert(x >= 0);
		if (x == 0 || x == 1)
		{
			return x;
		}
		float tmp = x;
		float xhalf = 0.5f*tmp;
		int i = *(int*)&tmp;
		
		i = 0x5f375a86 - (i >> 1); // 这一步是关键
		
		tmp = *(float*)&i;
		tmp = tmp*(1.5f - xhalf*tmp*tmp);
		tmp = tmp*(1.5f - xhalf*tmp*tmp);
		tmp = tmp*(1.5f - xhalf*tmp*tmp);
 
		int ret = 1 / tmp;
		if (ret*ret > x)
		{
			return ret - 1;
		}
		return ret;
	}
};
----------------------------------------------------
int x = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();
```
