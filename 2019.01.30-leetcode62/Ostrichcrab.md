```
#define ll long long
class Solution {
public:
    ll C(ll n, ll m)
    {
        if(m==0) return 1;
        return C(n,m-1)*(n-m+1)/m;
    }
    int uniquePaths(int m, int n) {
        int t = min(n,m);
        return C(n+m-2,t-1);
    }
};
```
