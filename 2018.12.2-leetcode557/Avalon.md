class Solution {
    public String reverseWords(String s) {
        String[] sArr = s.split(" ");
		StringBuilder sb = new StringBuilder();
		int len = sArr.length;
		for (int i=0;i<len;i++){
			char[] temp = sArr[i].toCharArray();
			int tlen = temp.length;
			for (int j=0;j<tlen;j++){
				sb.append(temp[tlen-1-j]);
			}
			if (i!=len-1)
				sb.append(" ");
		}
		return sb.toString();
    }
}
