class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> wlist = new ArrayList<>();
		int len = words.length;
		String template = getTemplate(pattern);
		for (int i=0;i<len;i++){
			if (words[i].length()==pattern.length()){
				String temp = getTemplate(words[i]);
				if (temp.equals(template))
					wlist.add(words[i]);
			}
		}
		return wlist;
    }
    
    private static String getTemplate(String pattern){
		char[] cs = pattern.toCharArray();
		List<Character> cl = new ArrayList<>();
		String result="";
		int len = cs.length;
		for (int i=0;i<len;i++){
			if (cl.contains(cs[i]))
				result+=String.valueOf(cl.indexOf(cs[i])+1);
			else{
				cl.add(cs[i]);
				result += String.valueOf(cl.size());
			}
		}
		return result;
	}
}
