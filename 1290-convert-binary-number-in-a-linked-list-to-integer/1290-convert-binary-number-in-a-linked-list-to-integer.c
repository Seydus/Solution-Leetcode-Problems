/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    int decimal_value = 0;
    struct ListNode* current = head;
    
    while (current != NULL) {
        decimal_value = (decimal_value << 1) | current->val;
        current = current->next;
    }
    
    return decimal_value;
}