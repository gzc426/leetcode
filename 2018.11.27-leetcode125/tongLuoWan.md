>leetcode 125. Valid Palindrome

```
class Solution {

    public boolean isPalindrome(String s) {
        if(s.length()==0)
    		return true;
        s=s.toLowerCase();
        int i = 0, j = s.length()- 1;
        while (i<j){
            if(!Character.isLetterOrDigit(s.charAt(i))) 
                i++;
            else if(!Character.isLetterOrDigit(s.charAt(j))) 
                j--;
            else if(s.charAt(i) != s.charAt(j)) 
                return false;
            else{ i++;j--;}
        }
        return true;        
    }
}
```
>2018.11.27号打卡
