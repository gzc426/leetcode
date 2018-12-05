     private static int solution(char[] charArray) {
        if (charArray.length == 0) {
            return 0;
        }
        //遍历整个字符数组
        //压缩后的字符长度
        int resultCount = 0;
        //当前重复字符计数
        int count = 1;
        for (int i = 0; i < charArray.length; i++) {
            //如果遇到某个字符与当前字符不相等或者已经遍历到最后一个字符
            if (i + 1 == charArray.length || charArray[i] != charArray[i + 1]) {
                //记录一下当前字符，并且resultCount加1，比如a,a,b,b,b，扫面到第二个a时
                //a!=b,如果a的个数大于1，先将a后面所有的a替换为数字，如a,a替换为a,2
                charArray[resultCount++] = charArray[i];
                if (count > 1) {
                    String temp = String.valueOf(count);
                    for (int k = 0; k < temp.length(); k++) {
                        charArray[resultCount++] = temp.charAt(k);
                    }
                }
                //重新统计下一个字符
                count = 1;
            } else {
                //统计重复的字符个数
                count++;
            }

        }
        return resultCount;
    }
