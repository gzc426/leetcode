```
class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i = 2; i <= n; i++)
        {
            dp[i]=-1;
            for(int j = 1; j < i; j++)
            {
                dp[i]=max(dp[i-j]*j,max(dp[i],j*(i-j)));
            }
        }
        return dp[n];
    }
};
```
```
class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        else if(n==3) return 2;
        else
       if(n%3==0) return pow(3,n/3);
        else if(n%3==2) return pow(3,n/3)*2;
        else return 2*2*pow(3,(n-4)/3);
    }
};
```
