import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> list = new ArrayList<>();
        if (root == null) {
            return list;
        }
        levelOrder(root,0,list);
        return list;
    }

    private void levelOrder(TreeNode root, int i, List<List<Integer>> list) {
        if (root == null)
            return;
        if (list.size() == i){
            List<Integer> a = new ArrayList<>();
            a.add(root.val);
            list.add(a);
        }else {
            list.get(i).add(root.val);
        }
        levelOrder(root.left,i+1,list);
        levelOrder(root.right,i+1,list);
    }
}
