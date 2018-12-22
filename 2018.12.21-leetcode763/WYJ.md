```java
class Solution {
    public List<Integer> partitionLabels(String S) {
        int[] end = new int[256];
        for(int i = 0; i < S.length(); i++){
            end[S.charAt(i)] = i;
        }
        int j = 0, anchor = 0;
        List<Integer> res = new ArrayList<>();
        for(int i = 0; i < S.length(); i++){
            j = Math.max(j, end[S.charAt(i)]);
            if(j == i){
                res.add(i - anchor + 1);
                anchor = i + 1;
            }
        }
        return res;
    }
}
```
