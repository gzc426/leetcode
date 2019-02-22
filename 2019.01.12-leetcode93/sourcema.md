# leetcode 93
    class Solution {
    public static List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();
        if (s == null || s.length() == 0||s.length()<4||s.length()>12) {
            return res;
        }
        dfs(s, res, 0, "");
        return res;
    }

    private static void dfs(String ip, List<String> res, int index, String ret) {
        if (index == 3) {
           if ((ip.length()==1||(ip.length()>1&&ip.length()<4&&ip.charAt(0)!='0'))
                    &&Integer.valueOf(ip) <= 255) {//Integer.valueOf(ip)防止ip的位数超出int范围 首位不能以0开头
                res.add(ret+ip);
            }
            return;
        }
        for (int i = 1; i < 4; i++) {
            String split = ip.substring(0, i>ip.length()?ip.length():i);//可能出现ip的长度小于i的情况，不够长度去切分
            if ((split.length()==1||(split.length()>1&&split.charAt(0)!='0'))
                    &&Integer.valueOf(split) <= 255) {
                ret = ret + split + ".";
                dfs(ip.substring(i>ip.length()?ip.length():i),res,index+1,ret);
                ret = ret.substring(0,ret.length() - split.length() - 1);
            }
        }
    }
}
