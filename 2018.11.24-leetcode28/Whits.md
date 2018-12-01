package AC;

import java.lang.reflect.Array;

public class leetcode_28_AC {

    
    
    public static void main(String[] args) {

        String haystack = "hello";
        String needle = "ll";
        System.out.println(strStrNew(haystack,needle));

    }
    public static int strStr(String haystack, String needle) {
        if (needle.length()==0)
            return 0;
        char[]hayStackCharArray =haystack.toCharArray();
        char[]needleCharArray = needle.toCharArray();
        for (int i = 0; i < hayStackCharArray.length; i++) {
            if (hayStackCharArray[i] == needleCharArray[0]) {   //第一个指针对比，若相同则进入if语句。
                int j = i+1;        //把此时的i+1赋值给k，直接比较第二个值
                int k = 1;          //直接比较第二个值
                for (; k<needleCharArray.length && j<hayStackCharArray.length; k++) {
                   if (hayStackCharArray[j] == needleCharArray[k])
                    j++;
                   else {
                       break;
                   }
                }
                if (needleCharArray.length==k){
                    return i;
                }
            }
        }
        return -1;
    }

    public static int strStrNew(String haystack, String needle){
       int hayStackLength  = haystack.length();
       int needleLength = needle.length();
       if (needleLength>hayStackLength) return -1; if (needleLength == 0) return 0;
        for (int i = 0; i<hayStackLength-needleLength;i++) {
            if (haystack.substring(i,needleLength+i).equals(needle))
                return i;
        }
        return -1;
    }
    /**
    * 还应该尝试下kmp算法
    * @author：liuquan
    * @date：2018/11/28 22:00
    * @param 
    * @return 
    */
    
}
