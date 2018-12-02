public class Solution {
    public String reverseWords(String s) {
        if(s == "")
            return "";
        String[] str = s.split(" ");
        String res = "";
        for (int i = str.length-1; i >=0; i--) {
           if(!str[i].equals("")){
                if (res.length()>0)
                   res += " ";
           }
           res += str[i];
        }
        return res;
    }
}
