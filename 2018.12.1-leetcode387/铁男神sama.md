
# 一

```
class Solution {
    public int firstUniqChar(String s) {
      int[] array=new int[26];
      for(char c:s.toCharArray()){
          array[c-'a']+=1;
      } 
      for(char c:s.toCharArray()){
          if(array[c-'a']==1)return s.indexOf(c);
      }
        return -1;
    }
}
```

# 二

