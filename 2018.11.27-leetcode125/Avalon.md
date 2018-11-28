class Solution {
    public boolean isPalindrome(String s) {
        if (s.length() == 0)//空字符串为回文串
			return true;
		char[] chars = s.toCharArray();
		int len = chars.length;
		List<Character> list1 = new ArrayList<>();
		for (int i= 0; i<len;i++){
			//全部转为小写
			if (chars[i]>='a'&&chars[i]<='z'){//小写比大写更大 32
				list1.add(chars[i]);
			}else if (chars[i]>='A'&&chars[i]<='Z'){
				list1.add((char)((int)chars[i]+32));//一句话转小写
			}else if (chars[i]>='0'&&chars[i]<='9'){
				list1.add(chars[i]);
			}
		}
		int listlen = list1.size();
        if (listlen == 0)
			return true;
		boolean flag = true;
		for (int i = 0; i < listlen /2 +1;i++){
			if (list1.get(i) != list1.get(listlen-1-i)){
				return false;
			}

		}
		return flag;
    }
}
