LeetCode387：https://leetcode-cn.com/problems/first-unique-character-in-a-string/

给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:

s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
 

注意事项：您可以假定该字符串只包含小写字母。

class Solution {
    
    // TODO 未用indexOf版本
    // public int firstUniqChar(String s) {
    //     s = s.trim();
    //     if("".equals(s)) return -1;
    //     if(s.length() == 1) return 0;
    //     char[] chars = s.toCharArray();
    //     outer:for(int i=0; i<chars.length; i++){
    //         for(int j=0; j<chars.length; j++){
    //             if(j == i) continue;
    //             if(chars[j] ==chars[i]){
    //                 continue outer;
    //             }
    //         }
    //         return i;
    //     }
    //     return -1;
    // }
}
