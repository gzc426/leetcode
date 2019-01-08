```
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int l=0;
        int h=nums.length-1;
        int answer[]=new int[2];
        int s=-1;
        int e=-1;
        int t=-1;
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]>target)
                h=m-1;
            else if(nums[m]<target)
                l=m+1;
            else{
                t=m;
                break;
            }
        }
        if(t==-1){
            answer[0]=-1;
            answer[1]=-1;
        }else{
            s=t;
            e=t;
            while(s>=0&&nums[s]==target){
                s--;
            }
            while(e<=nums.length-1&&nums[e]==target){
                e++;
            }
            s=s+1;
            e=e-1;
            answer[0]=s;
            answer[1]=e;
            
        }
        return answer;
    }
}

```
