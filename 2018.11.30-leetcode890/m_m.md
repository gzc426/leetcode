class Solution {

public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        
        //中序遍历，每个节点相当于有两个指针left=prior;right=next;
         
        //递归结束条件一定是写在递归循环外的
        
        if(pRootOfTree==NULL)
            return NULL;
        if(pRootOfTree->left==NULL&&pRootOfTree->right==NULL)   //考虑一个节点情况，也是递归结束条件
            return pRootOfTree;
        TreeNode *left=Convert(pRootOfTree->left);   //找到树的最左节点
        TreeNode *p=left;

        while(p!=NULL&&p->right!=NULL){
            p=p->right;
        }
       if(left!=NULL){
            p->right=pRootOfTree;
           pRootOfTree->left=p;
        }
        TreeNode *right=Convert(pRootOfTree->right);
        if(right!=NULL){
            right->left=pRootOfTree;
            pRootOfTree->right=right;
        }
        return left!=NULL?left:pRootOfTree;
        
      
    }
};
