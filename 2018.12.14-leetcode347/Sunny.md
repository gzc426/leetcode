```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int n: nums) {
            map.put(n, map.getOrDefault(n, 0) + 1);
        }
        List<Integer> result = new ArrayList<>();
        PriorityQueue<Integer> heap = new PriorityQueue<>((a, b) -> map.get(b) - map.get(a));
        for (int num : map.keySet()) {
            heap.add(num);
        }
        for (int j=0; j<k; j++) {
            result.add(heap.poll());
        }
        return result;
    }
}
```
