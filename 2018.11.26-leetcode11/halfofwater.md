# Prolem_011

### Solution 1:

```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int i=0, j=len-1, result=0, tmp=0;
        while(i<=j)
        {
            tmp = (j-i)*(height[j]>height[i]?height[i]: height[j]);
            if(tmp > result)
            {
                result = tmp;
            }
            height[j]>height[i]?i++:j--;
        }
        
        return result;
    }
};
```

### solution 2:

```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int p1 = 0;
        int p2 = len-1;
        int result = 0;
        int tmp = 0;
        for(int i=0;i<len;i++)
        {
            p1 = height[i];
            for(int j=len-1;j>=0;j--)
            {
                p2 = height[j];
                tmp = (j-i)*(p2 > p1?p1:p2);
                if(result < tmp)
                {
                    result = tmp;
                }
            }
        }
        return result;
        
    }
};
```

 **Obviously, the solution one is a better solution.**
