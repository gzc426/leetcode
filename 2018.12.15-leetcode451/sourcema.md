# LeetCode 451
    class Solution {
    public String frequencySort(String s) {//先按照value进行排序，然后排在前面的key值根据value的个数添加到最终的String中
         if (s == null || s.length() == 0) {
            return s;
        }
        TreeMap<Character, Integer> map = new TreeMap<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (map.containsKey(ch)) {
                map.put(ch, map.get(ch) + 1);
            } else {
                map.put(ch, 1);
            }
        }
        List<Map.Entry<Character, Integer>> list = new ArrayList<>(map.entrySet());
        Collections.sort(list, new Comparator<Map.Entry<Character, Integer>>() {
            @Override
            public int compare(Map.Entry<Character, Integer> o1, Map.Entry<Character, Integer> o2) {
                return o2.getValue()-o1.getValue();
            }
        });
        StringBuilder sb = new StringBuilder();
        for (Map.Entry<Character, Integer> entry : list) {
            for (int i=0;i<entry.getValue();i++) {
                sb.append(entry.getKey());
            }
        }
        return sb.toString();
    }
}
