package Leetcode;

public class for125 {
    public boolean isPalindrome(String s) {
        if(s.length()==0)
    		return true;
        //s=s.toLowerCase();
        char[] cs =s.toCharArray();
        int i = 0, j = cs.length - 1;
        while(i<j)
        {
        	if(!Character.isLetterOrDigit(cs[i]))
        		++i;
        	else if(!Character.isLetterOrDigit(cs[j]))
        		--j;
        	else if (Character.toLowerCase(cs[i]) == Character.toLowerCase(cs[j]))        		
            {
                ++i;
                --j;
            }
            else 
            return false;

        }
        return true;
    }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String reg="[^a-zA-Z0-9]";
		String s = "A man, a plan, a canal: Panama";
		char x ='A';
		x=Character.toLowerCase(x);
        s=s.toLowerCase();
        System.out.println(x);
	}

}
