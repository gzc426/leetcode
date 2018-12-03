class Solution {
   public String reverseWords(String s) {
       String [] list = s.split(" ");
       StringBuffer result = new StringBuffer();
       for(int i=0;i<list.length - 1;i++){
           result.append(reverse(list[i]) + " ");
       }
       result.append(reverse(list[list.length - 1]));
       return result.toString();
   }
   public String reverse(String s)
   {
       char [] charArray = s.toCharArray();
       int i =0;int j = charArray.length - 1;
       while(i < j)
       {
           char ch = charArray[i];
           charArray[i] = charArray[j];
           charArray[j] = ch;
           i++;
           j--;
       }
       return String.valueOf(charArray);
   }
}
