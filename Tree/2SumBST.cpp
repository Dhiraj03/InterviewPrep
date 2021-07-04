/*
Given a BST - with the 2Sum problem - Use BSTIterator for next and prev
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
stack<TreeNode *> low;
stack<TreeNode *> high;
void pushToLeft(TreeNode *root)
{
    while (root != NULL)
    {
        low.push(root);
        root = root->left;
    }
}

void pushToRight(TreeNode *root)
{
    while (root != NULL)
    {
        high.push(root);
        root = root->right;
    }
}

bool hasPrevious()
{
    return (!high.empty());
}

bool hasNext()
{
    return (!low.empty());
}

int increase()
{
    TreeNode *res = low.top();
    low.pop();
    pushToLeft(res->right);
    return res->val;
}

int decrease()
{
    TreeNode *res = high.top();
    high.pop();
    pushToRight(res->left);
    return res->val;
}

int Solution::t2Sum(TreeNode *root, int B)
{
    pushToLeft(root);
    pushToRight(root);

    int start = increase();
    int end = decrease();
    while (1)
    {
        if (start == end)
            return false;
        if (start + end == B)
            return 1;
        else if (start + end < B)
        {
            if (!hasNext())
                return 0;
            start = increase();
        }
        else if (start + end > B)
        {
            if (!hasPrevious())
                return 0;
            end = decrease();
        }
    }
}
