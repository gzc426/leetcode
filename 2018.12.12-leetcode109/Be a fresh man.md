## 109_(有序链表转换为二叉搜索树)Convert Sorted List to Binary Search Tree
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。<br>
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
### 1.2 输入与输出
输入：<br>
* ListNode* head：有序链表的头节点指针<br>
输出：<br>
* output_type:TreeNode*：高度平衡二叉搜索树的根节点指针
### 1.3 样例
#### 1.3.1 样例1<br>
输入: <br>
给定的有序链表： [-10, -3, 0, 5, 9]<br>
输出: <br>
一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：<br>

          0
         / \
	   -3   9
	   /   /
	 -10  5
	 

## 2 思路描述与代码    
### 2.1 思路描述（快慢指针+递归）
1. 快慢指针分离成左子树所有节点构成的链表、根节点和右子树所有节点构成的链表
2. 根据根节点递归分离的两个链表，第一个链表为左子树，第二个链表为右子树

比如给定的有序链表： [-10, -3, 0, 5, 9]<br>
先分离链表为list1 = [-10, -3], 根节点root的值 0, list2 = [5, 9];<br>
递归左子树root->left = sortedListToBST(list1), root->right = sortedListToBST(list2)<br>
根据同样的方法可以获取 root 左右二叉搜索子树分别是:

        -3      9
       /       /
     -10      5

于是构造出的二叉搜索树是:

          0
         / \
       -3   9
       /   /
     -10  5

### 2.2 代码
```cpp
//函数中涉及到的指针操作
//head 为 ListNode* 类型的指针， head->val 是这个指针所指向的节点的值
//head->next 为 head 所指向的节点的下一个节点的指针

//TreeNode* root = new TreeNode(val) 返回从堆中生成一个值为 val 的链表节点的指针给root
//root->left 是 root 所指向节点的左子树根节点的指针, root->right 同理

//解题思路
//1.快慢指针分离成左子树所有节点构成的链表、根节点和右子树所有节点构成的链表
//2.根据根节点递归分离的两个链表，第一个链表为左子树，第二个链表为右子树 
TreeNode* sortedListToBST(ListNode* head) {
    //边界情况:链表为空或者只有一个节点
    if(head == nullptr) return nullptr;
    if(head->next == nullptr) return new TreeNode(head->val);
    
    //1.快慢指针分离成根节点、左子树所有节点构成的链表和右子树所有节点构成的链表
    //slow为二叉搜索树左子树所有节点构成的链表的链表的尾巴，其链表头为head
    //slow->next->val为二叉搜索树根节点的值
    //slow->next->next为二叉搜索树右子树所有节点构成的链表的头节点指针
    ListNode *slow = head, *fast = head->next;
    while( fast != nullptr ){
        fast = fast->next == nullptr ? nullptr : fast->next->next;
        slow = fast == nullptr ? slow : slow->next;
    }
    //2. 根据根节点递归分离的两个链表，第一个链表为左子树，第二个链表为右子树
    TreeNode* root = new TreeNode(slow->next->val);
    slow->next = nullptr;//分离第一个链表
    ListNode* list2head = slow->next->next;//获取第二个链表的头节点指针
    //递归构造二叉搜索树
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(list2head);
    return root;
}
```
## 3 思考与拓展
### 3.1 思考
本题数据是基于链表的结构，获取中间值相比于数组是要花很大的代价的，所以时间复杂度变大了。
#### 3.1.1 其他方法
无。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
快慢指针+递归|O(n)|O(nlogn)
#### 3.1.3 难点分析
1. 快慢指针分离链表
2. 边界情况的考虑

### 3.2 拓展
如果给定的链表不是有序的呢？会影响他的时间复杂度吗？
