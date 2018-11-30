public class Solution {
    public String reverseWords(String s) {
        if(s==null || s.length()==0){
            return"";
        }
        String[] array=s.split(" ");
        String str="";
        for(int i = array.length-1;i>=0;--i){
            if(!array[i]equals("")){
                if(str.length()>0){
                    str+=" ";
                }
                str+=array[i];
            }
        }
        return str;
    }
}
