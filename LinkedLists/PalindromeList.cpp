/* Given a linked list, return true if it is a palindrom - in constant space and O(n) time
Approach :  Find the length of the list - split into half - reverse the second half and then
compare the reversed second half and the first half
*/
int len = 0;
ListNode *root = A;
while (root != NULL)
{
    len++;
    root = root->next;
}
if (len <= 1)
    return true;
root = A;
int i = 0;
int start;
if (len % 2 == 1)
    start = (len) / 2 + 2;
else
    start = (len / 2) + 1;
while (i < start - 1)
{
    root = root->next;
    i++;
}
ListNode *prevNode = NULL;
ListNode *nextNode;
while (root != NULL)
{
    nextNode = root->next;
    root->next = prevNode;
    prevNode = root;
    root = nextNode;
}
root = prevNode;
while (root && A)
{
    if (root->val != A->val)
    {
        return 0;
    }
    root = root->next;
    A = A->next;
}
return 1;