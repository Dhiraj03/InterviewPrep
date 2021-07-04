/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
int k;
int elt;
void inOrder(TreeNode *root, int &counter)
{
    if (counter > k)
        return;
    if (root == NULL)
        return;

    inOrder(root->left, counter);
    counter++;
    if (counter == k && root != NULL)
        elt = root->val;
    inOrder(root->right, counter);
}
int Solution::kthsmallest(TreeNode *A, int B)
{
    k = B;
    int counter = 0;
    inOrder(A, counter);
    return elt;
}
