```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        List<Integer> res = new ArrayList<>();
        if(nums.length == 0 || k <= 0){
            return res;
        }
        for(int i = 0; i < nums.length; i++){
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        }
        
        for(int i = 0; i < k; i++){
            int tempKey = 99999999;
            int tempValue = 0;
            for(Integer key : map.keySet()){
                if(map.get(key) > tempValue){
                    tempKey = key;
                    tempValue = map.get(key);
                }
            }
            res.add(tempKey);
            map.remove(tempKey);
        }
        return res;
    }
}
```
