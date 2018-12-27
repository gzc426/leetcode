```java
class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, (o1, o2) -> o1[0] != o2[0] ? Integer.compare(o2[0], o1[0]) : Integer.compare(o1[1], o2[1]));
        for (int i = 0; i < people.length; ++i) {
            int[] p = people[i];
            for (int j = i; j > p[1]; --j) {
                people[j] = people[j - 1];
            }
            people[p[1]] = p;
        }
        return people;
    }
}
```
