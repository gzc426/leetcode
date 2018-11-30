public int compress(char[] chars) {
        if (chars == null || chars.length == 0) {
            return 0;
        }
        int count = 1;
        char pre = chars[0];
        StringBuilder sb = new StringBuilder();

        for (int i = 1; i < chars.length; i++) {
            if (pre == chars[i]) {
                count++;
            }else {
                if (count > 1) {
                    sb.append(pre);
                    sb.append(count);
                } else if (count == 1) {
                    sb.append(pre);
                }
                pre = chars[i];
                count = 1;
            }
        }
        sb.append(pre);
        if (count > 1) {
            sb.append(count);
        }
        int i=0;
        for (char c : sb.toString().toCharArray()) {
            chars[i++] = c;
        }
        return sb.length();
    }
