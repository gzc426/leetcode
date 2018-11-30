# leetcode 125
    public static boolean isPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return true;
        }
        String str = s.toLowerCase();
        int left=0,right=s.length()-1;
        while (left < right) {
            while (left < right && !Character.isDigit(str.charAt(left)) && !Character.isAlphabetic(str.charAt(left))) {
                left++;
            }
            while (left < right && !Character.isDigit(str.charAt(right)) && !Character.isAlphabetic(str.charAt(right))) {
                right--;
            }
            if (str.charAt(left++) != str.charAt(right--)) {
                return false;
            }
        }
        return true;
    }
