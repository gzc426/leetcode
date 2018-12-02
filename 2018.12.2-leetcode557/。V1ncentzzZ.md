557. 反转字符串中的单词 III

给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

class Solution {
    
    // https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/submissions/
    
    // TODO 空复O(1) 未AC
  // public String reverseWords(String s) {
  //       s = s.trim();
  //       if(s.length() < 2) return s;
  //       char[] wordChar = s.toCharArray();
  //       String result = "";
  //       for(int i=0; i<=wordChar.length; i++){
  //           if(i == wordChar.length || ' ' == wordChar[i]){
  //               for(int j=i-1; j>=0; j--){
  //                   if(wordChar[j] == ' ' && j != wordChar.length - 1) {
  //                       result += " ";
  //                       break;
  //                   }
  //                   if(j == 0) result += " ";
  //                   // if(result.equals("") && wordChar[j] == ' ') continue;
  //                   // if(j == wordChar.length-1) 
  //                   result += wordChar[j];
  //               }
  //               continue;
  //           }
  //       }
  //       return result;
  //   }
    
    
     public String reverseWords(String s) {
        String[] strs = s.split(" ");
        StringBuilder sb = new StringBuilder();
        for(String str:strs){
            char[] chars = str.toCharArray();
            for(int i=0,j=chars.length-1;i<j;i++,j--){
                char temp = chars[i];
                chars[i] = chars[j];
                chars[j] = temp;
            }
            sb.append(new String(chars) + " ");
        }
        return sb.toString().trim();
    }

}
