/**
Given a binary tree and a linked list head, find whether the list exists in the tree.
Appraoch : Simple recursion.
*/
class Solution {
public:
    bool subPath(ListNode* head, TreeNode* root)
    {
        if(!head) return true;
        if(!root) return false;
        return head->val == root->val && (subPath(head->next, root->left) || subPath(head->next, root->right));
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;
        return subPath(head, root) || isSubPath(head, root->left) || isSubPath(head,root->right);
    }
};