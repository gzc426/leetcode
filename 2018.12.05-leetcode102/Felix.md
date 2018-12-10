```javascript
public static void levelOrder(Node head){
		if(head == null){
			return;
		}
		Queue<Node> queue = new LinkedList<>();
		queue.offer(head);
		while(!queue.isEmpty()){
			head = queue.poll();
			System.out.print(head.value + " ");
			if(head.left != null){
				queue.offer(head.left);
			}
			if(head.right != null){
				queue.offer(head.right);
			}
		}
	}

```
