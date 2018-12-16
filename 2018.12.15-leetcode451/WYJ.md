```java
class Solution {
    public String frequencySort(String s) {
        int[] freq = new int[256];
        for(int i = 0; i < s.length(); i++){
            freq[s.charAt(i)]++;
        }
        char[] res = new char[s.length()];
        for(int i = 0; i < s.length();){
            int index = findMaxIndex(freq);

            for(int j = 0; j < freq[index]; j++){
                res[i++] = (char)index;
            }
            freq[index] = 0;
        }
        return String.valueOf(res);
    }
    public int findMaxIndex(int[] freq){
        int temp = 0;
        int index = 0;
        for(int i = 0; i < freq.length; i++){
            if(temp < freq[i]){
                temp = freq[i];
                index = i;               
            } 
        }
        return index;
    }
}
```
