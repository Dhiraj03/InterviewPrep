/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
void preorder(TreeNode *root, vector<int> &res)
{
    if (root == NULL)
        return;

    res.push_back(root->val);

    preorder(root->left, res);
    preorder(root->right, res);
}
vector<int> Solution::preorderTraversal(TreeNode *A)
{
    vector<int> res;
    preorder(A, res);
    return res;
}
