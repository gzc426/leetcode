    private static String solution(String input) {
        String[] splits = input.split(" ");
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < splits.length; i++) {
            //对每个字符串进行反转
            sb.append(reverse(splits[i]) + " ");
        }
        return sb.toString();
    }

    private static String reverse(String str) {
        char[] charArray = str.toCharArray();
        int i = 0, j = charArray.length - 1;
        while (i < j) {
            char temp = charArray[i];
            charArray[i] = charArray[j];
            charArray[j] = temp;
            i++;
            j--;
        }
        return String.valueOf(charArray);
    }
