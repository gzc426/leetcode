



## 101.对称二叉树

> [https://leetcode-cn.com/problems/binary-tree-level-order-traversal/](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

### 一、题目

给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:给定二叉树: `[3,9,20,null,null,15,7]`,

```
                    3
                   / \
                  9  20
                    /  \
                   15   7
```

返回其层次遍历结果：

```
                [			
                  [3],
                  [9,20],
                  [15,7]
                ]
```

### 二、思路

- **层序遍历回顾：** 用队列。将根结点入队，只要队列不为空，就每次从队列中出队一个结点，打印它的值，如果当前出队的这个结点有左孩子，左孩子入队，有右孩子，则右孩子入队。

  ```java
  /*不换行*/
  public  void printByLevel(TreeNode root) {
  		if(root==null)return;
  		Queue<TreeNode> q = new LinkedList<>();
  		q.offer(root);
  		
  		while(!q.isEmpty()) {
  			TreeNode popNow = q.poll();
  			System.out.print(popNow.val);
  			System.out.print(" ");
  			if(popNow.left!=null) {
  				q.offer(popNow.left);
  			}
  			if(popNow.right!=null) {
  				q.offer(popNow.right);
  			}
  		}
  		System.out.println();
  	}
  /*换行：
  层序遍历打印二叉树是个很简单的问题，但是此题要求换行，不是简单的层序遍历了。关键问题就是需要去确定何时该换行。这就需要两个TreeNode类型的变量last和nLast。last表示正在打印的当前行最右节点，nLast表示下一行的最右结点。*/
  public  void printBylevel1(TreeNode root) {
  		if (root == null)
  			return;
  
  		Queue<TreeNode> q = new LinkedList<>();
  		int level = 1;
  		TreeNode last = root;
  		TreeNode nLast = null;
  		q.offer(root);
  		System.out.printf("Level%d:", level++);
  		while (!q.isEmpty()) {
  			TreeNode popNow = q.poll();
  			System.out.print(popNow.val + " ");
  
  			if (popNow.left != null) {
  				q.offer(popNow.left);
  				nLast = popNow.left;
  			}
  			if (popNow.right != null) {
  				q.offer(popNow.right);
  				nLast = popNow.right;
  			}
  			if (popNow == last && !q.isEmpty()) {
  				last = nLast;
  				System.out.printf("\nLevel%d:", level++);
  			}
  		}
  		System.out.println();
  	}
  ```



### 三、题解

#### 这是第一次ac：首先想到的是左神教的last和nlast做法，没能一次成功。于是画图，发现列队size()配合上BFS就能解出本题。

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
	public List<List<Integer>> breadthTraverse(TreeNode root) {
		List<List<Integer>> listAll = new ArrayList<>();
		Queue<TreeNode> q = new LinkedList<>();
		q.offer(root);
		if(root==null)return listAll;
		while (!q.isEmpty()) {
			List<Integer> list = new ArrayList<>();
			int size = q.size();
			for (int i = 0; i < size; i++) {
				//System.out.printf("size=%d\n",size);
				TreeNode popNow = q.poll();
				list.add(popNow.val);
				if (popNow.left != null) {
					q.offer(popNow.left);
				}
				if (popNow.right != null) {
					q.offer(popNow.right);
				}
			}
			listAll.add(list);
		}
		return listAll;
	}
}
```

#### 这是第二次ac：比较蠢，非要用左神的last和nlast，这回倒好了，直接解析String。。怎么说呢，有点无脑，好在8ms还可以接受。

```java
	public List<List<Integer>> levelOrder(TreeNode root) {
		List<List<Integer>> listAll = new ArrayList<>();
		if (root == null)
			return listAll;
		String s = printBylevel2(root);
		String[] sArray = s.split("\n");
		for (int i = 0; i < sArray.length; i++) {
			List<Integer> list = new ArrayList();
			for (String ss : sArray[i].split(" ")) {
				list.add(Integer.parseInt(ss));
			}
			listAll.add(list);
		}
		// System.out.println("TorF?");
		return listAll;
	}

	public String printBylevel2(TreeNode root) {
		if (root == null)
			return "";
		StringBuilder sb = new StringBuilder();
		Queue<TreeNode> q = new LinkedList<>();
		int level = 1;
		TreeNode last = root;
		TreeNode nLast = null;
		q.offer(root);

		while (!q.isEmpty()) {
			TreeNode popNow = q.poll();
			sb.append(popNow.val + " ");

			if (popNow.left != null) {
				q.offer(popNow.left);
				nLast = popNow.left;
			}
			if (popNow.right != null) {
				q.offer(popNow.right);
				nLast = popNow.right;
			}
			if (popNow == last && !q.isEmpty()) {
				last = nLast;
				sb.append("\n");
			}
		}
		return sb.toString();
	}
```

#### 这是第三次ac：在上面的基础上，发现了小秘密，其实只要在左神的解法上稍作改动就能完成此题。

```java
public List<List<Integer>> levelOrder(TreeNode root) {
		List<List<Integer>> listAll = new ArrayList<>();
		if (root == null)
			return listAll;
		Queue<TreeNode> q = new LinkedList<>();
		int level = 1;
		TreeNode last = root;
		TreeNode nLast = null;
		q.offer(root);
		List<Integer> list = new ArrayList();
		while (!q.isEmpty()) {
			int size = q.size();
			TreeNode popNow = q.poll();
			list.add(popNow.val);
			if (popNow.left != null) {
				q.offer(popNow.left);
				nLast = popNow.left;
			}
			if (popNow.right != null) {
				q.offer(popNow.right);
				nLast = popNow.right;
			}
			if (popNow == last) {
				last = nLast;
				listAll.add(list);
				list=new ArrayList<Integer>();
			}
		}
		return listAll;
	}
```

