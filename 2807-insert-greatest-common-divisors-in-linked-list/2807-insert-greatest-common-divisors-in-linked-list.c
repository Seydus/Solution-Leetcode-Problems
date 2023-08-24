/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    
    struct ListNode *curr = head, *newNode = NULL;

    while (curr->next != NULL) {
        newNode = malloc(sizeof(struct ListNode));
        newNode->val = gcd(curr->val, curr->next->val);
        
        newNode->next = curr->next;
        curr->next = newNode;

        curr = curr->next->next;
    }

    return head;
}
