```java
class Solution {
    private List<String> res = new ArrayList<>();
    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0){
            return res;
        }
        String[] dic = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        dfs(digits, 0, "", dic);
        return res;
        
    }
    private void dfs(String digits, int index, String s, String[] dic){
        if(index == digits.length()){
            res.add(s);
            return;
        }
        int num = digits.charAt(index) - '0';
        for(int i = 0; i < dic[num].length(); i++){
            dfs(digits, index + 1, s + String.valueOf(dic[num].charAt(i)), dic);
        }
        return;
    }
}
```
