/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution
{
    public IList<int> PostorderTraversal(TreeNode root)
    {
        IList<int> result = new List<int>();
        travel(result, root);
        return result;
    }

    private void travel(IList<int> result, TreeNode node)
    {
        if (node == null)
        {
            return;
        }

        travel(result, node.left);
        travel(result, node.right);
        result.Add(node.val);
    }
}