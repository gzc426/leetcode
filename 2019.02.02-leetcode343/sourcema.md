# leetcode 343
    class Solution {
    public int integerBreak(int n) {
        if(n==1){
            return n;
        }
        if(n==2){
            return 1;
        }
        if(n==3){
            return 2;
        }
        int num=n/3;
        int res=n%3;
        int ans=0;
        if(res==0){
            ans=(int)Math.pow(3,num);
        }
        if(res==1){
            ans=(int)Math.pow(3,num-1)*4;
        }
        if(res==2){
            ans=(int)Math.pow(3,num)*2;
        }
        return ans;
    }
}
