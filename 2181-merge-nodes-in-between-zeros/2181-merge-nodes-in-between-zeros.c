/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head){
    struct ListNode* mHead;
    struct ListNode* travPlus;
    struct ListNode* result;
    struct ListNode** resultTrav = &result;
    int value = 0;
    
    for(mHead = head->next; mHead != NULL; mHead = mHead->next)
    {
        if(mHead->val != 0)
        {
            struct ListNode* temp = malloc(sizeof(struct ListNode));
            
            for(travPlus = mHead; travPlus != NULL && travPlus->val != 0; travPlus = travPlus->next)
            {
                value += travPlus->val;
            }
            
            if(travPlus != NULL)
            {
                temp->val = value;
                temp->next = NULL;
                value = 0;
                
                *resultTrav = temp;
                resultTrav = &(*resultTrav)->next;
            }
            
            mHead = travPlus;
        }
    }
    
    return result;
}