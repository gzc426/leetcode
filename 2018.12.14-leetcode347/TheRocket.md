```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        // 构造一个从整数到出现次数的映射
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        // 构造一个桶，桶内存放数据，桶的下标表示该数的出现次数
        List<Integer>[] buckets = new ArrayList[nums.length + 1];
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int num = entry.getKey();
            int count = entry.getValue();
            if (buckets[count] == null) {
                buckets[count] = new ArrayList<>();
            }
            buckets[count].add(num);
        }
        List<Integer> topK = new ArrayList<>(k);
        // 从后往前遍历桶，即从出现次数高的到出现次数低的，注意跳过不存在的桶
        for (int i = buckets.length - 1; i >= 0 && topK.size() < k; --i) {
            if (buckets[i] != null) {
                topK.addAll(buckets[i]);
            }
        }
        return topK;
    }
}
```
