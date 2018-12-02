public class Solution {
    public String reverseWords(String s) {
        int length=s.length();
        //当字符串为空
        if(s == null){ return null;}
        //当字符串为"    "时 直接返回null
        if(s.trim().equals("")){
            return s.trim();   
        }
        /**
         * 先将字符串按照空格分裂为字符串数组
         * 然后收尾两个指针来交换即可
         */
        //0.掐头去尾
        String allRevStr=s.trim();
        //1.将字符串按照空格分裂为字符串数组
        String[] strChar=allRevStr.split(" ");

        //2.使用首尾两个指针来交换
        int left=0;
        int right=strChar.length-1;
        String temStr=null;
        while(left<right){
            //交换
            temStr=strChar[left];
            strChar[left]=strChar[right];
            strChar[right]=temStr;
            //移动指针
            left++;
            right--;
        }
        //3.拼接好新的字符串
        String reverse="";
        for (int i=0; i<strChar.length; ++i) { 
            //对每一个单词掐头去尾
            String temp=strChar[i].trim();
            
            if (temp.equals("")) {
                continue;
            }

            if (i==strChar.length-1) {
                reverse=reverse+temp;
            }else{
                reverse=reverse+temp+" ";
            }
        }
        return reverse;
    }
}
