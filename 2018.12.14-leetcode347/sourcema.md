# LeetCode 347
    class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
         Map<Integer, Integer> map = new TreeMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                map.put(nums[i], map.get(nums[i]) + 1);
            } else {
                map.put(nums[i], 1);
            }
        }
        List<Map.Entry<Integer, Integer>> list = new ArrayList<>(map.entrySet());//不能直接通过value进行排序，需要转换成List进行排序
        Collections.sort(list, new Comparator<Map.Entry<Integer, Integer>>() {
            @Override
            public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
                return o2.getValue()-o1.getValue();
            }
        });
        List<Integer> res = new ArrayList<>();
        for (int i=0;i<k;i++) {
            res.add(list.get(i).getKey());
        }
        return res;
    }
}
