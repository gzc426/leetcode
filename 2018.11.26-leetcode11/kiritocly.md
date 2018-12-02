

    private static int solution(int[] array) {
        //从左右两边同时遍历，每次都舍弃最短边
        int left = 0;
        int right = array.length - 1;
        int resultTemp = 0;
        int result = 0;
        while (left < right) {
            if (array[left] <= array[right]) {
                //左边柱子低于右边
                //计算临时盛水容量
                resultTemp = array[left] * (right - left);
                //矮柱子向中间移动
                left++;
            } else if (array[left] >= array[right]) {
                //左边柱子高于右边
                //计算临时盛水容量
                resultTemp = array[right] * (right - left);
                //矮柱子向中间移动
                right--;
            }
            //判断临时盛水容量
            if (resultTemp > result) {
                result = resultTemp;
            }
        }
        return result;
    }
