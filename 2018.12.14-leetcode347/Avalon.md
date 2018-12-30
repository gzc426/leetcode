class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        HashMap<Integer,Integer> map =new HashMap<>();
		int len = nums.length;
		Integer tempInt;
		Integer current;
		for (int i=0;i<len;i++){
			current = nums[i];
			if (map.containsKey(current)){
				tempInt = map.get(current);
				map.put(current, ++tempInt);
			}else {
				map.put(current, 1);
			}
		}
		List<Map.Entry<Integer,Integer>> list_Data=new ArrayList<>(map.entrySet());
		Collections.sort(list_Data,new Comparator<Map.Entry<Integer,Integer>>(){

			@Override
			public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
				return o2.getValue().compareTo(o1.getValue());
			}
		});
		List<Integer> result = new ArrayList<>();
		for (int i=0;i<k;i++){
			result.add(list_Data.get(i).getKey());
		}
		return result;
    }
}
