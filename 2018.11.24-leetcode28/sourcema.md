# LeetCode 28
     public static int strStr(String haystack, String needle) {
        if (needle.length() == 0) {
            return 0;
        }
        if (haystack.length() == 0 || haystack == null || needle.length() > haystack.length()) {
            return -1;
        }
        int hStart,nStart;
        for (int i = 0; i < haystack.length(); i++) {
            hStart=i;
            nStart=0;
            while (nStart < needle.length() && hStart < haystack.length()) {
                if (haystack.charAt(hStart) == needle.charAt(nStart)) {
                    hStart++;
                    nStart++;
                } else {
                    break;
                }
                if (nStart == needle.length()) {
                    return i;
                }

            }
        }
        return -1;
    }
