```java
class Solution {
    public String reverseWords(String s) {
        String result = "";
        String[] words = s.split(" ");
        for(String word : words){
            char[] chars = word.toCharArray();
            int j = chars.length-1;
            for(int i =0;i<j;i++){
                char a = chars[i];
                chars[i] = chars[j];
                chars[j] = a;
                j--;
            }
            result += String.valueOf(chars)+" ";
        }
        return result.trim();
    }
}
