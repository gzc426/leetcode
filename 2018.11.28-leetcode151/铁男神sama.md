
```java
public class Solution {
    public String reverseWords(String s) {
        StringBuilder sb = new StringBuilder();
        String[] sArray=new StringBuilder(s).reverse().toString().split(" ");
        for(int i=0;i<sArray.length;i++) {
            if(!sArray[i].equals("")) {
                if (i != sArray.length - 1) {
                     sb.append(new StringBuilder(sArray[i]).reverse()).append(" ");
                     } else {
                     sb.append(new StringBuilder(sArray[i]).reverse());
                     }
            }

        }
    	return sb.toString();
	}

}
```


```java
public class Solution {
    public String reverseWords(String s) {
       
		char[] chas =s.toCharArray();
		reverse(chas,0,chas.length-1);
		int r=-1;
		int l=-1;
		for(int i=0;i<chas.length;i++){
			if(chas[i]!=' '){
				l=i==0||chas[i-1]==' '?i:l;
				r=i==chas.length-1||chas[i+1]==' '?i:r;
              }
			if(l!=-1&&r!=-1){
				reverse(chas,l,r);
				l=-1;
				r=-1;
			}
		}
		return String.valueOf(chas).trim().replaceAll("\\s+", " "); 
    }
    public void reverse(char[] chas,int start,int end){
        char tmp=0;
        while(start<end){
            tmp=chas[start];
            chas[start]=chas[end];
            chas[end]=tmp;
            start++;
            end--;
        }
    }
}
```


