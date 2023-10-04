/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* parentHead = NULL;
    struct ListNode** trav = &parentHead;
    
    while (1) {
        int smallestIndex = -1;

        for (int i = 0; i < listsSize; i++) {
            if (lists[i] != NULL && (smallestIndex == -1 || lists[i]->val < lists[smallestIndex]->val)) {
                smallestIndex = i;
            }
        }

        if (smallestIndex == -1) {
            break;
        }

        *trav = lists[smallestIndex];
        lists[smallestIndex] = lists[smallestIndex]->next;
        trav = &(*trav)->next;
    }

    return parentHead;
}