​       
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
