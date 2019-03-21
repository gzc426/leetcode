# leetcode 413
    class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        if(A==null||A.length==0){
            return 0;
        }
        int res=0;
        for(int i=0;i<A.length;i++){
            for(int j=i+1;j<A.length;j++){
                if(j-i>=2&&isArithmetic(A,i,j)){
                    res+=1;
                }
            }
        }
        return res;
    }
    public boolean isArithmetic(int[] arr,int i,int j){
        int d=arr[i+1]-arr[i];
        for(int k=i+1;k<j;k++){
            if(arr[k+1]-arr[k]!=d){
                return false;
            }
        }
        return true;
    }
}
