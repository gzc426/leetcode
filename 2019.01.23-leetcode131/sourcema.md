# LeetCode 131
    class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        if (s == null || s.length() == 0) {
            return res;
        }
        find(res, new ArrayList<String>(), s);
        return res;
    }
    private  void find(List<List<String>> res, ArrayList<String> list, String s) {
        if (s.length() == 0) {
            res.add(new ArrayList<String>(list));
            return;
        }
        for (int i = 1; i <=s.length() ; i++) {
            String temp = s.substring(0, i);
            if (IsPalindrome(temp)) {
                list.add(temp);
                find(res,list,s.substring(i));
                list.remove(list.size() - 1);
            }
        }

    }
    private  boolean IsPalindrome(String temp) {
        int left=0;int right=temp.length()-1;
        while (left < right) {
            if (temp.charAt(left) != temp.charAt(right)) {
                return false;
            }else{
                left++;
                right--;
            }
        }
        return true;
    }
}
