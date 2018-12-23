# LeetCode 763
    class Solution {
    public List<Integer> partitionLabels(String S) {
        //先找到首字母最后出现的位置，然后遍历从首字母第一次出现到最后一次出现之间的位置，
        // 看是否有元素最后出现的位置超过首字母最后出现的位置，如果有更新最后出现的位置下标，如果没有这段区间可以划分为一个段，重复以上步骤即可得到最终结果。
        if (S == null || S.length() == 0) {
            return new ArrayList<Integer>();
        }
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < S.length();) {
            int index = S.lastIndexOf(S.charAt(i));
            for (int j = i+1; j < index; j++) {
                if (S.lastIndexOf(S.charAt(j)) > index) {
                    index=S.lastIndexOf(S.charAt(j));
                }
            }
            list.add(index - i + 1);
            i=index+1;
        }
        return list;
    }
}
