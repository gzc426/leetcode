# 一

```java
class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> list=new ArrayList<>();
        for(int i=0;i<words.length;i++){
            String eachWord=words[i];
            if(eachWord.length()!=pattern.length())continue;
            if(isIsomorphic(eachWord,pattern))list.add(eachWord);
        }
        return list;
    }
    public boolean isIsomorphic(String s, String t) {
		if (s == null || t == null || s.length() != t.length()) {
			return false;
		}
		char[] chas1 = s.toCharArray();
		char[] chas2 = t.toCharArray();
		int[] map = new int[512];
		for (int i = s.length() - 1; i >= 0; i--) { 
			if (map[chas1[i]] != map[chas2[i] + 256]) {
				return false;
			}
			map[chas1[i]] = map[chas2[i] + 256] = i;
		}
		return true;
	}
}
```

