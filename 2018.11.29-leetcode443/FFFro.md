class Solution {
    public int compress(char[] chars) {
        int count = 1;
        int index = 0;
        for (int i = 0; i < chars.length; i++) {
            if (i == chars.length-1 || chars[i] != chars[i+1]) {
                chars[index++] = chars[i];
                if (count > 1) {
                    String a = String.valueOf(count);
                    for (int k = 0; k < a.length(); k++) {
                        chars[index++] = a.charAt(k);
                    }
                }
                count = 1;
            } else {
                    count++;
            }
        }
        return index;
    }
}
