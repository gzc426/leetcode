    // TODO 执行比较慢，有冗余代码，待优化 7ms
    public int compress(char[] chars) {
        if(chars.length == 0) return 0;
        char temp = chars[0];
        int count = 0;
        int len = 0;
        for(int i=0; i<chars.length; i++){
            if(chars[i] == temp) count++;
            if(chars[i] != temp){
                chars[len++] = temp;
                if(count > 1){
                    char[] step = String.valueOf(count).toCharArray();
                    chars[len++] = step[0];
                    if(count > 9) chars[len++] = step[1];
                }
                temp = chars[i];
                count = 1;
            }
            if(i == chars.length - 1) {
                chars[len++] = temp;
                if(count > 1){
                    char[] step = String.valueOf(count).toCharArray();
                    chars[len++] = step[0];
                    if(count > 9) chars[len++] = step[1];
                }
                continue;
            }
        }
        return len;
    }
