/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

void inorder(TreeNode *root, vector<int> &res)
{
    if (root == NULL)
        return;

    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}
vector<int> Solution::inorderTraversal(TreeNode *A)
{
    vector<int> res;
    inorder(A, res);
    return res;
}
