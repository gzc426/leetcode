```java
class Solution {
  public static int firstUniqChar(String s) {
		int result = -1;
		char[] chars = s.toCharArray();
		for (int i = 0; i < chars.length; i++) {
			if (s.lastIndexOf(chars[i]) == s.indexOf(chars[i])) {
				result = i;
				break;
			}
		}
		return result;
	}

}
