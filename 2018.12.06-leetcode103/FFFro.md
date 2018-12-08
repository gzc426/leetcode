class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
       List<List<Integer>> list = new ArrayList<>();
            if (root == null) {
                return list;
            }
            levelOrder(root,list,0);
            return list;
        }

        private void levelOrder(TreeNode root, List<List<Integer>> list, int level) {
            if (root == null)
                return;
            if (level == list.size()){
                List<Integer> temp = new LinkedList<>();
                list.add(temp);
            }
            if (level % 2 == 0)
                list.get(level).add(root.val);
            else
                list.get(level).add(0,root.val);

            levelOrder(root.left, list,level+1);
            levelOrder(root.right, list,level+1);
        }
}
