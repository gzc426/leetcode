102_(二叉树的层次遍历)Binary Tree Level Order Traversal
 ## 1 问题描述、输入输出与样例
 ### 1.1 问题描述
 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。<br>
 ### 1.2 输入与输出
 输入：<br>
 * TreeNode* root：二叉树的根节点指针<br>
 输出：<br>
 * vector<vector<int>>：层次遍历的结果，是一个二维矢量的形式
 ### 1.3 样例
 #### 1.3.1 样例1
 输入: 给定二叉树: [3,9,20,null,null,15,7],
     
         3
        / \
       9  20
         /  \
        15   7

 输出: 

     [
       [3],
       [9,20],
       [15,7]
     ]

遍历二叉树，首先访问二叉树的第一层元素，再访问第二层，第三层，实现方式，用一个先进先出的队列作为辅助数据结构，
维护一个当前结点数目，和下一层结点数目，当前层遍历层，加入数据集
public List<List<Integer>> levelOrder(TreeNode root){
           List<List<Integer>> ret = new ArrayList<>();
           if(root == null)
                 return ret;
           levelOrderCore(root,ret);
           return ret;
}

public void levelOrderCore(Treenode root, List<List<Interger>> ret){
              //标记下一行有多少元素
              int nextCount =0;
              //当前层有多少结点，为1 是根结点初始化
              int curCount =1;
              Queue<TreeNode> q= new LinkedList<>();
              q.offer(root);
              List<Integer> tmp = new ArrayList<>();
              while(!q.isEmpty()){
                       TreeNode node = q.poll();
                       tmp.add(node.val);
                       //遍历结点当前个数减去1
                       curCount--;
                       if(node.left != null){
                              q.offer(node.left);
                              //左右孩子属于下一层结点
                              nextCount++;
                       }
                       if(node.right != null){
                             q.offer(node.right);
                             nextCount++;
                       }
                       //如果当前层遍历完，加入结果集
                       if(curCount ==0){
                               curCount = nextCount;
                               nextCount =0;
                               ret.add(new ArrayList<>(tmp));
                               rmp.clear();
                       }

              }

}
