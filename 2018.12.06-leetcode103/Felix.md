```javascript
public ArrayList<ArrayList<Integer>> zigzagLevelOrder(TreeNode root) {
		ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
		Stack<TreeNode> stack1 = new Stack<TreeNode>();
		Stack<TreeNode> stack2 = new Stack<TreeNode>();
		int layer = 1;//层数
		stack1.push(root);
		while(!stack1.isEmpty() || !stack2.isEmpty()){
			if(layer%2!=0){//奇数层
				ArrayList<Integer> list = new ArrayList<Integer>();
				while(!stack1.isEmpty()){
					TreeNode node = stack1.pop();
					if(node != null){
						list.add(node.val);
						stack2.push(node.left);//从左到右
						stack2.push(node.right);
					}
				}
				if(!list.isEmpty()){
					res.add(list);
					layer++;
				}
			}else{//偶数层
				ArrayList<Integer> list = new ArrayList<Integer>();
				while(!stack2.isEmpty()){
					TreeNode node = stack2.pop();
					if(node != null){
						list.add(node.val);
						stack1.push(node.right);//从右到左
						stack1.push(node.left);
					}
				}
				if(!list.isEmpty()){
					res.add(list);
					layer++;
				}
			}
		}
		
		return res;
    }
```
