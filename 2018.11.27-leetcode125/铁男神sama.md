```Java
class Solution {
    public boolean isPalindrome(String s) {
        char[] charArray = s.toCharArray();
        int index=0;
        for(char c:charArray){
            if(c>=65&&c<=90 ){
                charArray[index++]=c;
            }else if(c>=97&&c<=122){
                charArray[index++]=(char)(c-32);
            }else if(c>=48&&c<=57) {
                charArray[index++]=c;
            }     
        }
        System.out.print(charArray);
        int start=0;
        int end=index-1;
        while(start<=end){
            if(charArray[start]==charArray[end]){
                start++;
                end--;
            }else{
                return false;
            }
            
        }
        return true;
	}
}
```

