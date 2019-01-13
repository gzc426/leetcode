		/**
     * 二分法
     * 因为比较太多运行时间也没有更短
     */
    public char nextGreatestLetter1(char[] letters, char target) {
        int length = letters.length;
        if (letters[0] - target < 0 && letters[length - 1] - target < 0){
            return letters[0];
        }
        int start = 0;
        int end = length - 1;
        int binary = 0;
        int distance = Integer.MAX_VALUE;
        char res = ' ';
        while (start <= end) {
            binary = (start + end) / 2;
            if (letters[binary] - target > 0){
                if (letters[binary] - target < distance){
                    res = letters[binary];
                    distance = letters[binary] - target;
                }
                if(end - start == 0){
                    return res;
                }
                end = binary - 1;
            }else {
                start = binary + 1;
            }
        }
        return res;
    }
		
		public char nextGreatestLetter(char[] letters, char target) {
        for (int i = 0; i < letters.length; i++) {
            if (letters[i] - target > 0){
                return letters[i];
            }
        }
        return letters[0];
   }
