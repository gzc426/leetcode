java

/**
 * 验证回文串
 *
 */
public class A7 {
    public boolean isPalindrome(String s) {
        if (s.isEmpty())
            return true;
​
        int begin = 0;
        int end = s.length() - 1;
​
        char beginChar, endChar;
​
        while (begin <= end){
            beginChar = s.charAt(begin);
            endChar = s.charAt(end);
            if (!Character.isLetterOrDigit(beginChar)){
                begin++;
                continue;
            }
            else if (!Character.isLetterOrDigit(endChar)){
                end--;
                continue;
            }
            else {
                if (Character.toLowerCase(beginChar) != Character.toLowerCase(endChar))
                    return false;
                else{
                    begin++;
                    end--;
                }
            }
        }
​
        return true;
    }
​
    public static void main(String[] args) {
        A7 a = new A7();
        String s1 =  "A man, a plan, a canal: Panama";
        String s2 =  "race a car";
        boolean res1 = a.isPalindrome(s1);
        boolean res2 = a.isPalindrome(s2);
        System.out.println(res1);
        System.out.println(res2);
    }
}
