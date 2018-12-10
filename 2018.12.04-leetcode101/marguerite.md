101_(对称二叉树)Symmetric Tree
给定一个二叉树，检查它是否是镜像对称的。

输入：
TreeNode* root：二叉树的根节点指针
输出：
bool：是否是对称二叉树

输入: 给定二叉树: [1,2,2,3,4,4,3] ,
    1
   / \
  2   2
 / \ / \
3  4 4  3
输出: true

solution1

判断是否是镜像对称，重要的就是判断对应位置的2个结点的值是否相等。用双端队列来实现 

public boolean isSymmetric(TreeNode root){
         if(root == null){
            return true;
          }
       //队列做遍历
       Deque<TreeNode> deque = new LinkedList<TreeNode>();
       //根节点不用判断，直接加入左右孩子结点
       deque.addFirst(root.left);
       deque.addLast(root.right);

       TreeNode preNode = null;
       TreeNode postNode = null;
  
       while(!deque.isEmpty()){
          //取出列队两个元素
          preNode = deque.pollFirst();
          postNode = deque.pollLast();
          //如果当前结点是空结点，结束本次循环，即不需要检查后续结点
          if(preNode == null && postNode == null){
             continue;
           }
          //如果不对称返回false，
          if(preNode == null || postNode == null){
             return false;
          }
          if(preNode.val != postNode.val){
              return false;
          } else{
             deque.addFirst(preNode.right);//preNode右孩子入队
             deque.addFirst(preNode.left);//preNode左孩子入队

             deque.addLast(postNode.left);//postNode左孩子入队
             deque.addLast(postNode.right);//postNode右孩子入队
          }
          }
         return true;//都是对称的返回真
   }


solution2
     public boolean isSysmmetric2(TreeNode root){
         if(root == null){
           return true; 
      }
          return checkNodes(root.left,root.right);  
      }

      public boolean checkNodes(TreeNode node1,TreeNode node2){
         if(node1 == null && node2 == null){
            return true;
         }
          if(node1 == null || node2 == null){
            return false;
         }
          if(node1.val != node2.val){
            return false;
         } else{
            return checkNodes(node1.left,node2.right) && checkNodes(node1.right,node2.left);
          }
        }
















