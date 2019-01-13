```java
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> dict = new HashSet<>(wordList);
        if (!dict.contains(endWord)) {
            return 0;
        }
        Set<String> head = new HashSet<>();
        Set<String> tail = new HashSet<>();
        head.add(beginWord);
        tail.add(endWord);
        int level = 1;
        while (!head.isEmpty() && !tail.isEmpty()) {
            ++level;
            if (head.size() > tail.size()) {
                Set tmp = head;
                head = tail;
                tail = tmp;
            }
            Set<String> newHead = new HashSet<>();
            for (String word : head) {
                char[] cs = word.toCharArray();
                for (int i = 0; i < cs.length; ++i) {
                    char ch = cs[i];
                    for (char j = 'a'; j <= 'z'; ++j) {
                        cs[i] = j;
                        String s = new String(cs);
                        if (tail.contains(s)) {
                            return level;
                        }
                        if (dict.contains(s)) {
                            dict.remove(s);
                            newHead.add(s);
                        }
                    }
                    cs[i] = ch;
                }
            }
            head = newHead;
        }
        return 0;
    }
}
```
