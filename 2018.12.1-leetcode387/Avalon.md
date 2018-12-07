class Solution {
    public int firstUniqChar(String s) {
        char[] storeArr = new char[26];//暂时存储数组，根据出现的顺序
		int[] numArr = new int[26];//存储数目

		char[] sArr = s.toCharArray();
		int len = sArr.length;
		for (int i=0;i<len;i++){
			for (int j=0;j<26;j++){
				if (storeArr[j] == 0){
					storeArr[j] = sArr[i];
					numArr[j]=1;
					break;
				}
				if (storeArr[j] == sArr[i]){
					numArr[j] += 1;
					break;
				}
			}
		}
		int temp = -1;
		for (int i =0;i<26;i++){
			if (numArr[i]==1){
				temp = i;
				break;
			}
		}
		int result = 0;
		if (temp == -1)
			return -1;
		else {
			for (int i = 0;i<len;i++){
				if (storeArr[temp]== sArr[i]){
					result = i;
					break;
				}
			}
		}
		return result;
    }
}
