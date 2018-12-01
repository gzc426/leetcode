class Solution {
    public int firstUniqChar(String s) {
		 if(null == s || 0 == s.length() ) 
             return -1;
    int[] hash = new int[26];//记录26个字母的字符数组
    char[] array = s.toCharArray();//将字符串转为字符数组
        
    for(int i = 0; i < array.length; i++){      
        int num = array[i] - 'a';
        
        hash[num]++;
    }
    for(int i = 0; i < array.length; i++){//从字符串出发
        	 //获得26个字母的下标
        int num = array[i] - 'a';
        if(hash[num] == 1){
            return i;
        }
    }
    return -1;
	}
}
