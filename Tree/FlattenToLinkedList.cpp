/*
 Given a tree, flatten it to a linked list - 
 Approach : have a function which converts the subtree 
 rooted at a particular node to a linked list and returns the last element in the list.
 First, store the right node, and perform conversion on left node - if the last element is
 NULL, then make lastNode the node itself, then perform this on right node, if the last node is still null,
 then set it to the previous last node - return the last node
*/
TreeNode *preOrder(TreeNode *root)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
        return root;
    TreeNode *rightNode = root->right;
    TreeNode *leftLast = preOrder(root->left);
    if (leftLast == NULL)
        leftLast = root;
    else
        root->right = root->left;
    root->left = NULL;
    TreeNode *rightLast = preOrder(rightNode);
    if (rightLast == NULL)
        return leftLast;
    else
        leftLast->right = rightNode;
    return rightLast;
}
TreeNode *Solution::flatten(TreeNode *A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    preOrder(A);
    return A;
}
