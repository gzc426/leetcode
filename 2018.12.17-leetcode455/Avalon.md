class Solution {
    public int findContentChildren(int[] g, int[] s) {
        /**
		 * 第一步：排序
		 */
		Arrays.sort(g);
		Arrays.sort(s);//按照从小到大进行排序
		int gIndex =0,count = 0;
		for (int i=0;i<s.length;i++){
			for (int j=gIndex;j<g.length;j++){
				if (s[i]>=g[gIndex]){
					count++;
					gIndex++;
                    break;
				}
			}
		}
		return count;
    }
}
