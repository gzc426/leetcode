    private static String solution(String input) {
        if ("".equals(input) || input == null) {
            return "";
        }
        String[] splits = input.split(" ");
        //反转字符串中的单词,从尾到头遍历
        //单词之间以空格分离
        String result = " ";
        for (int i = splits.length - 1; i >= 0; i--) {
            if (!splits[i].equals("")) {
                //单词不为空
                result = result + splits[i];
            }
        }
        return result;
    }
