class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        char[] charArray = s.toCharArray();
        String res = "";
        for (int i = 0; i < charArray.length; i++) {
            if ((int)charArray[i]>=48&&(int)charArray[i]<=57 || (int)charArray[i]>=97&&(int)charArray[i]<=122)
                res+=charArray[i];
        }
        char[] array = res.toCharArray();
        int start = 0;
        int end = array.length-1;
        while (end>start){

            if(array[start] == array[end]){
                start++;
                end--;
            }else {
                return false;
            }
        }
        return true;

    }
}
