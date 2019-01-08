class Solution {
    public List<Integer> partitionLabels(String S) {
        if (S == null || S.length() == 0) return null;
		
		List<Integer> list = new ArrayList<>();

		//region 开始解题
		//System.out.println('b'-'a');//1-->创建一个二维数组
		///1.创建一个二维数组,存储起止位置
		int[][] stored = new int[26][];//26个英文字母
		int start, end;
		for (int i = 0; i < 26; i++) {//没有时为-1
			start = S.indexOf((char) ('a' + i));
			end = S.lastIndexOf((char) ('a' + i));
			stored[i] = new int[]{start, end};
		}
		Stream stream = Arrays.stream(stored);//转换为stream 进行操作
		//stream.forEach(p-> System.out.println(Arrays.toString((int[])p)));
		//2.筛选不需要的部分 + 按照 start 位置进行排序
		int[][] tempResult = (int[][]) stream.filter(p -> ((int[]) p)[0] > -1).sorted((e1, e2) -> ((int[]) e1)[0] - ((int[]) e2)[0]).toArray(int[][]::new);//通过流转化为数组
		//3.通过贪婪算法得出结果

		int j = 1, i = 0;//count=0,
		for (; j < tempResult.length; j++) {
			if (tempResult[i][1] > tempResult[j][0]) {//结束位置覆盖开始位置-》
				if (tempResult[i][1] < tempResult[j][1])
					tempResult[i][1] = tempResult[j][1];
			} else {
				list.add(tempResult[i][1] - tempResult[i][0] + 1);
				i = j;
			}
		}
		list.add(tempResult[i][1] - tempResult[i][0] + 1);
		//endregion


		return list;
    }
}
