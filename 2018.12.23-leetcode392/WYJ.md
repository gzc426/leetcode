```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        if(s.length() == 0){
            return true;
        }
        int indexS = 0, indexT = 0;
        while(indexT < t.length()){
            if(t.charAt(indexT) == s.charAt(indexS)){
                indexS++;
            }
            indexT++;
            if(indexS == s.length()){
                return true;
            }
        }
        return false;
    }
}
```
