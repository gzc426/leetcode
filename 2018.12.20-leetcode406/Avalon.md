class Solution {
    public int[][] reconstructQueue(int[][] people) {
        //按照身高降序，位置升序进行排序
		Arrays.sort(people,(x,y)->x[0]==y[0]?x[1]-y[1]:y[0]-x[0]);

		List<int[]> templist = new LinkedList<>();
		for (int[] p :
				people) {
			templist.add(p[1], p);
		}
		return templist.toArray(new int[templist.size()][]);
    }
}
