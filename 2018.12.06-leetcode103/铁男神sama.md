## 103.锯齿打印(ZigZag)二叉树

> [https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)

### 一、题目

给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：给定二叉树 `[3,9,20,null,null,15,7]`,

```
                        3
                       / \
                      9  20
                        /  \
                       15   7
```

返回锯齿形层次遍历如下：

```
                    [
                      [3],
                      [20,9],
                      [15,7]
                    ]
```

### 二、思路

- 就是用一个双端队列（或者两个栈）和一个flag标志
- 具体描述：从左到右时，让结点从队列头弹出，该结点的孩子从队尾进入；从右到左时，从队尾弹出结点，该结点的孩子从队头进入。
- 

### 三、题解

#### 第一次ac：就是 思路描述的双端队列方法，当然也可以用两个栈实现。

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> listAll = new ArrayList<>();
        if(root==null)return listAll;
		Deque<TreeNode> q = new LinkedList<>();
		q.offerFirst(root);
		boolean flag = true;
		while (!q.isEmpty()) {
			List<Integer> list = new ArrayList<>();
			int size = q.size();//本层结点个数
			for (int i = 0; i < size; i++) {
				TreeNode popNow;
				if (flag) {
					popNow = q.pollFirst();
					if (popNow.left != null) {
						q.offerLast(popNow.left);
					}
					if (popNow.right != null) {
						q.offerLast(popNow.right);
					}
				}else {
					popNow = q.pollLast();
					if (popNow.right != null) {
						q.offerFirst(popNow.right);
					}
					if (popNow.left != null) {
						q.offerFirst(popNow.left);
					}
				}
				list.add(popNow.val);
			}
			listAll.add(list);
			flag=!flag;
		}
		return listAll;
    }
}
```

#### 第二解：在leetcode上提交看到的答案，主要方法是：用当前层数来控制从左还是从右开始，(上面的是用flag标志，都差不多)；没想到的是他用了个list.add(0,node.val)，方便了很多。

```java
 public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> listAll = new ArrayList<>();
        if(root == null)return listAll;
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);
        int depth = 0;
        while(!queue.isEmpty()){
            int count = queue.size();
            List<Integer> list = new ArrayList<Integer>();
            while(count > 0){
                TreeNode node = queue.poll();
                if(depth%2 == 1){
                    list.add(0,node.val);             
                }else{
                    list.add(node.val);
                }
                if(node.left != null) queue.add(node.left);
                if(node.right != null) queue.add(node.right);   
                count--;
            }
            depth++;
            listAll.add(list);
        }
        return listAll;
    }
```

#### 第三解：leetcode上的，用了这个Collections.reverse(list) ，虽然我想提高自己造轮子的能力，尽量不用库函数解题，但不得不承认，这些东西还是挺方便的。

```java
public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
		List<List<Integer>> listAll = new ArrayList<List<Integer>>();
		if (root == null) return result;
		Queue<TreeNode> q = new LinkedList<TreeNode>();
		q.add(root);
		TreeNode node = null;
		boolean flag = true;
		while (!queue.isEmpty()) {
			int count = queue.size();
			List<Integer> list = new ArrayList<>();
			while (count > 0) {
				node = queue.poll();
				list.add(node.val);
				if (node.left != null)
					queue.add(node.left);
				if (node.right != null)
					queue.add(node.right);
				count--;
			}
			if (flag) {
				listAll.add(list);
				flag = false;
			} else {
				Collections.reverse(list);
				listAll.add(list);
				flag = true;
			}
		}
		return listAll;
	}
```



