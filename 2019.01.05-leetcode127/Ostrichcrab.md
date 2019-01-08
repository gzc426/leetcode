```
public class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        
        Set<String> wordSet = new HashSet<>(wordList);
        Set<String> visited = new HashSet<>();
        visited.add(beginWord);
        int dist = 1;

        while (!visited.contains(endWord)) {
            Set<String> temp = new HashSet<>();
            for (String word: visited) {
                for (int i = 0; i < word.length(); i++) {
                    char[] chars = word.toCharArray();
                    for (int j = (int)'a'; j < (int)'z' + 1; j++) {
                        chars[i] = (char)j;
                        String newWord = new String(chars);
                        if (wordSet.contains(newWord)) {
                            temp.add(newWord);
                            wordSet.remove(newWord);
                        }
                    }
                }
            }
            dist += 1;            
            if (temp.size() == 0) { // it nevert get to the endWord
                return 0;
            }

            visited = temp;
        }

        return dist;
    }
}
```
