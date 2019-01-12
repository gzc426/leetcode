```java
class Solution {
    private List<String> res = new ArrayList<>();
    public List<String> restoreIpAddresses(String s) {
        dfs(s, 0, "", 0);
        return res;
    }
    private void dfs(String s, int index, String ip, int splitNum){
        if(splitNum == 4){
            if(index >= s.length()){
                res.add(ip.substring(0, ip.length() - 1)); 
            }
            return;
        }
        for(int i = 1; i < 4&&index + i <= s.length(); i++){
            String temp = s.substring(index, index + i);
            if(temp.length() >1&&temp.charAt(0) == '0'){
                return;
            }
            int num = Integer.valueOf(temp);
            if(num > 255|| num < 0){
                return;
            }
            dfs(s, index + i, ip + temp + ".", splitNum + 1);
        }
        return;
    }
}
```
