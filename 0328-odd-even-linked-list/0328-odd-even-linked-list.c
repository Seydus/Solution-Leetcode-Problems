/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head){

 if(head == NULL || head->next == NULL || head->next->next == NULL)
 {
     return head;
 }

 struct ListNode* secondHead = &*head->next;

 struct ListNode* trav;
 struct ListNode* odd = &*head;
 struct ListNode* even = &*head->next;
 
 int i = 0;

 for(trav = &*even->next, i = 1; trav != NULL; trav = trav->next, i++)
 {
     if(i % 2 != 0)
     {
        odd->next = trav;
        odd = odd->next;
     }
     else
     {
        even->next = trav;
        even = even->next;
     }
 }
 
  even->next = NULL;
  odd->next = secondHead;
  return head;
}
