/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode** trav;
    
    for(trav = &node;  (*trav)->next != NULL; trav = &(*trav)->next)
    {
        (*trav)->val = (*trav)->next->val;
    }
    
    *trav = NULL;
}