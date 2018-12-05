class Solution {
    public int lengthOfLastWord(String s) {
        String[] sArr = s.trim().split(" ");
		if (sArr.length == 0)
			return 0;
		return sArr[sArr.length-1].length();
    }
}
