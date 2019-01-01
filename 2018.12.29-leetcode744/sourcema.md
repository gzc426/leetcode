# LeetCode 744
    class Solution {
    public char nextGreatestLetter(char[] letters, char target) {//简单的二分思路
           //test 
	int left=0;
	int right=letters.length-1;
	while(left<=right){
		int mid=(left+right)>>1;
		if(letters[mid]>target){
			right=mid-1;
		}else {
			left=mid+1;
		}
	}
	return letters[left%letters.length];
    }
}
