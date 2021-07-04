/**
Define an iterator for BST.
Appraoch - Have a stack, when iterator is initialized, push all left nodes to a stack.
If stack is not empty, hasNext() should return true.
When next is called, get the top element, pop, push all left of its right subtree
and then return the value of the popped element
*/
class BSTIterator
{
public:
    stack<TreeNode *> nodeStack;
    BSTIterator(TreeNode *root)
    {
        pushAllLeft(root);
    }
    void pushAllLeft(TreeNode *root)
    {
        while (root != NULL)
        {
            nodeStack.push(root);
            root = root->left;
        }
    }
    /** @return the next smallest number */
    int next()
    {
        TreeNode *res = nodeStack.top();
        nodeStack.pop();
        pushAllLeft(res->right);
        return res->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return (!nodeStack.empty());
    }
};

/**
* Your BSTIterator object will be instantiated and called as such:
* BSTIterator* obj = new BSTIterator(root);
* int param_1 = obj->next();
* bool param_2 = obj->hasNext();
*/