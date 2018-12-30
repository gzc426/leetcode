```java
/**
 *将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 *
 *本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 *
 */
public class Tree3
{
    public static class TreeNode
    {
        int data;
        TreeNode left;
        TreeNode right;
        TreeNode(int val)
        {
            data = val;
        }
    }

    public TreeNode sortedArrayToBST(int[] nums)
    {
        if (nums.length == 0)
            return null;
        else
            return buildBST(nums,0,nums.length - 1);
    }

    private TreeNode buildBST(int[] nums, int start, int end)
    {
        if (start <= end)
        {
            int mid = (start + end) / 2;
            TreeNode root = new TreeNode(nums[mid]);
            root.left = buildBST(nums, start, mid - 1);
            root.right = buildBST(nums, mid + 1, end);
            return root;
        }
        else
            return null;
    }

    //中序遍历验证结果
    public static void midPrint(TreeNode p)
    {
        if (p != null)
        {
            midPrint(p.left);
            System.out.print(p.data + " ");
            midPrint(p.right);
        }
    }

    public static void main(String[] args)
    {
        Tree3 t = new Tree3();
        int[] a = new int[]{-10,-3,0,5,9};

        TreeNode p = t.sortedArrayToBST(a);

        midPrint(p);
    }

}
```