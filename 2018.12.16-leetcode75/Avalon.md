class Solution {
    public void sortColors(int[] nums) {
        List<Integer> list0 = new ArrayList<>();//红色
		List<Integer> list1 = new ArrayList<>();//白色
		List<Integer> list2 = new ArrayList<>();//蓝色
		for (int i=nums.length-1;i>=0;i--){
			if (nums[i]==0)list0.add(0);
			else if(nums[i]==1)list1.add(1);
			else if (nums[i]==2)list2.add(2);
		}

		for (int i=0;i<list0.size();i++){
			nums[i]=0;
		}
		int len1 =list0.size();
		for (int i=0;i<list1.size();i++){
			nums[len1+i]=1;
		}
		int len2= list0.size()+list1.size();
		for (int i=0;i<list2.size();i++){
			nums[len2+i]=2;
		}
    }
}
