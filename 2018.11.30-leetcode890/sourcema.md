# LeetCode 890
    class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> list = new ArrayList<>();
        if (words.length == 0 || words == null) {
            return list;
        }
        for (int i = 0; i < words.length; i++) {
            String temp = words[i];
            if (match(temp, pattern)) {
                list.add(temp);
            }
        }
        return list;
    }
    private static boolean match(String temp, String pattern) {
        Map<Character, Character> map1 = new HashMap<>();
        Map<Character, Character> map2 = new HashMap<>();
        for (int i = 0; i < temp.length(); i++) {
            Character t = temp.charAt(i);
            Character p = pattern.charAt(i);
            if (!map1.containsKey(t)) {
                map1.put(t, p);
            }
            if (!map2.containsKey(p)) {
                map2.put(p, t);
            }
            if (map1.get(t) != p || map2.get(p) != t) {
                return false;
            }
        }
        return true;
    }
}
