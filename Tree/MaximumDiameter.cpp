/**
Given a tree, return the maximum diameter of the tree - the maximum distance (calculated as the number of edges)
between any two nodes in the tree.
Approach : For every node, check the path that covers maximum depth on left and right sides and includes it - if this
is greater than the max, reset max.
Return the max of leftHeight and rightHeight +1.
*/
class Solution
{
public:
    int res = 0;
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int maxHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return max(maxHeight(root->left), maxHeight(root->right)) + 1;
    }
    int maxPath(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (maxHeight(root->left) + maxHeight(root->right) + 1 > res)
            res = maxHeight(root->left) + maxHeight(root->right) + 1;
        return max(maxPath(root->left), maxPath(root->right)) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int h = maxPath(root);
        if (h == 0 && res == 0)
            return 0;
        return res > h ? res - 1 : h - 1;
    }
};