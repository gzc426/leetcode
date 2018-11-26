/**
 * @author: ChenforCode
 * @date: 2018/11/26 14:29
 * @description: 验证回文串，只验证数字和字符
 */
public class Solution {
    public static void main(String[] args){
        System.out.println(isPalindrome("A man, a plan, a canal: Panama"));
    }

    public static boolean isPalindrome(String s) {
        char[] chars = s.toCharArray();
        int i = 0, j = chars.length - 1;
        while (i < j){
            if (!Character.isLetterOrDigit(chars[i])){
                i++;
            } else if (!Character.isLetterOrDigit(chars[j])){
                j--;
            } else {
                if (Character.toLowerCase(chars[i]) == Character.toLowerCase(chars[j])){
                    i++;
                    j--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
}
