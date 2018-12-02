```java
class Solution {
    public int compress(char[] chars) {
       int start = 0;
        int end = 0;
        //定义两指示字符的标识符
        for(int i = 0;i < chars.length;i++){
            if(i==chars.length-1||chars[i+1] != chars[i]){//如果不同或遍历到最后一个
            chars[start] = chars[end];//在前一个字符计数后记录字母
                start++;
                if(end < i){//当前指示位置与遍历位置不一致
                    int sum = i-end+1;//对重复计数
                    if(sum < 10){
                    chars[start++] =(char)(sum+ '0');
                }else{
                    chars[start++]=(char)(sum/10+ '0');
                    chars[start] = (char)(sum % 10+ '0');
                    start++;
                }
                }
                end = i + 1;//保证遍历位置与标记位置相同
            }
        }
          return start;
    
    }
}
```
