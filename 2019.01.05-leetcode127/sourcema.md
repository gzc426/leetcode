# LeetCode 127
    class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> set = new HashSet<>(wordList);
        if(!set.contains(endWord)){
            return 0;
        }
        Queue<String> queue=new LinkedList<String>();
        queue.add(beginWord);
        int step=1;
        while(!queue.isEmpty()){
            int size=queue.size();
            for (int i = 0; i < size; i++) {
                String s = queue.poll();
                for (int k = 0; k < s.length(); k++) {
                    char[] chars = s.toCharArray();
                    for (char j = 'a'; j <= 'z'; j++) {
                        chars[k] = j;
                        String temp = String.valueOf(chars);
                        if (set.contains(temp)) {
                            if (temp.equals(endWord)) {
                                return step + 1;
                            }
                            queue.add(temp);
                            set.remove(temp);
                        }
                    }
                }
            }
            step++;
        }
        return 0;

    }
}
