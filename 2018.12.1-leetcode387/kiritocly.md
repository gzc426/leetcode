     private static int solution(String input) {
        //只出现一次的字符的编号，以leetcode为例
        int index = 1;
        //26个英文字母，初始化一个长度为26的整形数组,第一个位置表示a的值，
        //第二个位置表示b的值，依此类推，数组中有三类值，-1，0，大于等于1的整数
        //-1表示字母出现两次或两次以上，0表示从未出现，大于等于1的整数表示只出现一次
        //的字母的序号
        int[] array = new int[26];
        for (int i = 0; i < input.length(); i++) {
            //将字符串中的字符转化为数组中的下标,例如a的asc码值为97，对应数组中的下标为0
            int charIndex = (int)input.charAt(i) - 97;
            if (array[charIndex] == 0) {
                //第一次出现,序号为index
                array[charIndex] = index;
                //index自增，记录下一个第一次出现的字符
                index++;
            } else {
                //字符已经出现过，即一个字符出现两次或者两次以上
                array[charIndex] = -1;
            }
        }
        char result = '#';
        //遍历array数组，找到最小的index,index>=1
        //记录最小的index
        int resultIndex = Integer.MAX_VALUE;
        for (int j = 0; j < array.length; j++) {
            if (array[j] > 0 && array[j] < resultIndex) {
                resultIndex = array[j];
                result = (char)(j + 97);
            }
        }
        if (result == '#') {
            return -1;
        }
        //找到result在字符串中第一次出现的位置
        for (int k = 0; k < input.length(); k++) {
            if (result == input.charAt(k)) {
                return k;
            }
        }
        return -1;
    }
