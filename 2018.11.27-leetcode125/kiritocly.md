    private static boolean solution(String input) {
        if (input == null || "".equals(input)) {
            return true;
        }
        char[] inputCharArray = input.toCharArray();
        //定义两个指针，一个头指针一个尾指针
        int head = 0;
        int tail = inputCharArray.length - 1;
        //判断字母和数字字符的正则表达式
        String regex = "^[0-9a-zA-Z]$";
        while (head <= tail) {
            String headStr = inputCharArray[head] + "";
            String tailStr = inputCharArray[tail] + "";
            if (headStr.matches(regex) && tailStr.matches(regex)) {
                if (headStr.toLowerCase().equals(tailStr.toLowerCase())) {
                    //比较下一个字符
                    head++;
                    tail--;
                } else {
                    //如果未匹配则直接返回
                    return false;
                }
            } else {
                //如果比较的字符不为字母或数字则不比较
                if (!headStr.matches(regex)) {
                    head++;
                }
                if (!tailStr.matches(regex)) {
                    tail--;
                }
            }
        }
        return true;
    }
