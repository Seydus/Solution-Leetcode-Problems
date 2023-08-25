#include <math.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getDecimalValue(struct ListNode* head) {
    struct ListNode* current = head;
    int power = 0, result = 0;
    
    for(; current != NULL; current = current->next) {
        power++;
    }
    
    current = head;
    
    for(; current != NULL; current = current->next) {
        if(current->val != 0)
        {
            result += pow(2, power - 1);
        }
        
        power--;
    }
    
    return result;
}