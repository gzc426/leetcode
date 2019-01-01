```java
class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        List<Character>[] buckets = new ArrayList[s.length() + 1];
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            char c = entry.getKey();
            int count = entry.getValue();
            if (buckets[count] == null) {
                buckets[count] = new ArrayList<>();
            }
            buckets[count].add(c);
        }
        StringBuilder sb = new StringBuilder();
        for (int i = buckets.length - 1; i >= 0; --i) {
            if (buckets[i] != null) {
                for (char c : buckets[i]) {
                    for (int j = 0; j < i; ++j) {
                        sb.append(c);
                    }
                }
            }
        }
        return sb.toString();
    }
}
```
