# LeetCode 151
    1. public static String reverseWords(String s) {//first method
        if (s.length() == 0 || s == null) {
            return s;
        }
        String str = s.trim();
        String[] split = str.split(" +");
        String result = "";
        for (int i = split.length - 1; i >=0; i--) {
            result += split[i] + " ";
        }
        return result.substring(0, result.length() - 1);
    }
    2. public static String reverseWords2(String s) {//two method
        if (s.length() == 0 || s == null) {
            return s;
        }
        String str = s.trim();//" "此时str为""
        char[] chars = str.toCharArray();
        reverse(chars, 0, chars.length - 1);
        //String target = new StringBuilder(str).reverse().toString();
        String result = "";
        int left=0,right=0;
       //char[] chars = target.toCharArray();
        while (right < chars.length) {
            while (right<chars.length&&chars[right] != ' ') {
                right++;
            }
            reverse(chars, left, right - 1);
            result+=String.valueOf(Arrays.copyOfRange(chars, left, right))+" ";
            while (right < chars.length && chars[right] == ' ') {
                right++;
            }
            left=right;
        }
        return result.length()==0?result:result.substring(0,result.length()-1);
    }

      private static void reverse(char[] chars, int i, int j) {
          while (i < j) {
              swap(chars, i++, j--);
          }
      }

      private static void swap(char[] chars, int i, int j) {
          char ch = chars[i];
          chars[i] = chars[j];
          chars[j] = ch;
      }
