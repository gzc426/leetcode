# leetcode 257
    class Solution {
        public List<String> binaryTreePaths(TreeNode root) {
            List<String> list = new ArrayList<>();
            if (root == null) {
                return list;
            }
            dfs(root, list,new String());
            return list;
        }
        private void dfs(TreeNode root, List<String> list,String ret) {
            if (root.left==null&&root.right==null) {
                ret+=root.val;
                list.add(ret);
                return;
            }
            ret += root.val + "->";
            if(root.left!=null){
            dfs(root.left,list,ret);
            }
            if(root.right!=null){
            dfs(root.right,list,ret);
            }
        }
    }
