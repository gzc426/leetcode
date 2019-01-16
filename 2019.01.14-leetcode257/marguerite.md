```
 /**
     * 递归方式
     * @param root
     * @return
     */
     
 ```
    public List<String> binaryTreePaths(TreeNode root) {
        if (root == null) {
            return resultList;
        }
        List<String> singleResult = new ArrayList<>();

        getTreePath(root, singleResult);
        return resultList;
    }
    
```
 /**
     * DFS深度优先遍历
     * @param resultList
     * @param node
     * @param singleResult
     */
```     
    private void getTreePath(TreeNode node, List<String> singleResult) {
        singleResult.add(node.val + "");
        if (node.left == null && node.right == null) {
            resultList.add(getPath(singleResult));
        }
        if (node.left != null) {
            getTreePath(node.left, new ArrayList<>(singleResult));
        }
        if (node.right != null) {
            getTreePath(node.right, new ArrayList<>(singleResult));
        }
    }
```
