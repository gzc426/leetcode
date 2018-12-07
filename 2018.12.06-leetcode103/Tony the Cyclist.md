```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
import java.util.*;

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> list = new ArrayList<>();
        if (root == null){
            return list;
        }
        ArrayDeque<TreeNode> d = new ArrayDeque<>();
        ArrayList<Integer> tmp = new ArrayList<>();
        d.addFirst(root);
        tmp.add(root.val);
        int flag = 0;
        tmp.clear();
        int level = 1;
        while (!d.isEmpty()){
            TreeNode node = d.pollLast();
            tmp.add(node.val);
            level --;
            if (node.left != null){
                d.addFirst(node.left);
            }
            if (node.right != null){
                d.addFirst(node.right);
            }
            if (level == 0){
                if (flag == 0){
                    flag = 1;
                }
                else if (flag == 1){
                    Collections.reverse(tmp);
                    flag = 0;
                }
                list.add(new ArrayList<>(tmp));
                level = d.size();
                tmp.clear();
            }
        }
        return list;
    }
}
```

```python
from collections import deque
class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root == None:
            return []
        elif root.right == None and root.left == None:
            return [[root.val]]
        d = deque([])
        result = [[root.val]]
        d.appendleft(root.left)
        d.appendleft(root.right)
        flag = 0
        level = 2
        tmp = []
        while len(d) != 0:
            node = d.pop()
            level -= 1
            if node != None:
                tmp.append(node.val)
                if node.left != None:
                    d.appendleft(node.left)
                if node.right != None:
                    d.appendleft(node.right)
            if level == 0:
                if flag == 1:
                    result.append(tmp)
                    flag = 0
                else:
                    tmp.reverse()
                    result.append(tmp)
                    flag = 1
                tmp = []
                level = len(d)
        return result
```
