/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

void postorder(TreeNode *root, vector<int> &res)
{
    if (root == NULL)
        return;

    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
}
vector<int> Solution::postorderTraversal(TreeNode *A)
{
    vector<int> res;
    postorder(A, res);
    return res;
}
