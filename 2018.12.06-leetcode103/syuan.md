##### 题目

```
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]
```
#### 代码
##### 两个栈

```
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> resList=new ArrayList<>();
        Stack<TreeNode> stack1=new Stack<>();
        Stack<TreeNode> stack2=new Stack<>();
        if (root==null) {
            return resList;
        }

        stack1.push(root);
        int index=1;
        while(!stack1.isEmpty() || !stack2.isEmpty()){
            int length1=stack1.size();
            int length2=stack2.size();
            List<Integer> tempList=new ArrayList<>();
            if (index%2!=0) {
                for (int i=0; i<length1; i++) {
                    if (stack1.peek().left!=null) {
                        stack2.push(stack1.peek().left);
                    }
                    if (stack1.peek().right!=null) {
                        stack2.push(stack1.peek().right);
                    }
                    tempList.add(stack1.pop().val);
                }
                index++;
            }else{
                for (int i=0; i<length2; i++) {
                    if (stack2.peek().right!=null) {
                        stack1.push(stack2.peek().right);
                    }
                    if (stack2.peek().left!=null) {
                        stack1.push(stack2.peek().left);
                    }
                    tempList.add(stack2.pop().val);
                }
                index++;
            }
            
            resList.add(tempList);
        }
        return resList;
    }
}
```
##### 递归

```
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res=new ArrayList<>();
        zigzagLevelOrderHelp(res,root,0);
        return res;
    }

    public void zigzagLevelOrderHelp(List<List<Integer>> res,TreeNode root,int index){
        if (root==null) return;

        if (res.size()<=index) {
            res.add(new ArrayList<>());
        }
        if (index%2==0) {
            res.get(index).add(root.val);
        }else{
            res.get(index).add(0,root.val);
        }
        zigzagLevelOrderHelp(res,root.left,index+1);
        zigzagLevelOrderHelp(res,root.right,index+1);
    }
}
```
> add(index,int) 该函数可以对一个数组进行前序插入  其余的会往后挪动
