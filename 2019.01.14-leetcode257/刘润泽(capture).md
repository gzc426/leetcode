```java
    public List<String> binaryTreePaths(TreeNode root) {

        List<String> res = new ArrayList<>();
        if (root==null) return res;
        deepsearch(root, "", res);
        return res;
    }

    public void deepsearch(TreeNode node, String currStr, List<String> res){

        if (node.left==null&&node.right==null) {
            currStr = currStr + node.val;
            res.add(currStr);
            return;
        }

        currStr = currStr + node.val + "->";

        if (node.left!=null) deepsearch(node.left,currStr,res);
        if (node.right!=null) deepsearch(node.right,currStr,res);
    }
```
