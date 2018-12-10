```java
class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> result = new ArrayList<>();
        for (String word : words) {
            int l = pattern.length();
            if (word.length() == l) {
                boolean valid = true;
                Map<Character, Character> p = new HashMap<>(l);
                for(int i=0; i<l; i++) {
                    char c = pattern.charAt(i);
                    char d = word.charAt(i);
                    Character v = p.get(c);
                    if (v != null) {
                        if (v != d) {
                            valid = false;
                            break;
                        }
                    } else {
                        if (p.containsValue(d)) {
                            valid = false;
                            break;
                        }
                        p.put(c, d);
                    }
                }
                if (valid) {
                    result.add(word);
                }
            }
        }
        return result;
    }
}
```
