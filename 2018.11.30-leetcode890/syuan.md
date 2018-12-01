```
class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> result=new LinkedList<>();
        int pHashCode=getHashCode(pattern);
        for (String word : words) {
            if (getHashCode(word)==pHashCode) {
                result.add(word);
            }
        }
        return result;
    }

    public int getHashCode(String word){
        int[] arr=new int[26];
        int hashCode=0,i=1;
        for (char c : word.toCharArray()) {
            if (arr[c-'a']==0) {
                arr[c-'a']=i++;
            }
            hashCode=hashCode*11+arr[c-'a'];
        }
        return hashCode;
    }
}
```
