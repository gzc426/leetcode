```
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3) return 0;
        int now = 0;
        int ans = 0;
        for(int i = 2; i < A.size(); i++){
            if(A[i]-A[i-1] == A[i-1]-A[i-2]) now++;
            else now = 0;
            ans+=now;
        }
        
       return ans; 
    }
};
```
