#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

typedef struct Node 
{
    int key;
    int value;
    int index;
    struct Node* next;
} Node;

typedef struct 
{
    Node* buckets[SIZE];
} HashSet;

int hashCode(int key)
{
    if (key < 0) 
    {
        return (SIZE + (key % SIZE)) % SIZE;
    }
    return key % SIZE;
}

HashSet* createHashSet()
{
    HashSet* set = (HashSet*)malloc(sizeof(HashSet));

    for (int i = 0; i < SIZE; i++)
    {
        set->buckets[i] = NULL;
    }

    return set;
}

void insert(HashSet* set, int key, int value, int index)
{
    Node *item = (Node*)malloc(sizeof(Node));
    item->key = key;
    item->value = value;
    item->index = index;
    item->next = NULL;

    int hashIndex = hashCode(key);

    if (set->buckets[hashIndex] == NULL)
    {
        set->buckets[hashIndex] = item;
    }
    else
    {
        Node* current = set->buckets[hashIndex];
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = item;
    }
}

int search(HashSet* set, int key)
{
    int hashIndex = hashCode(key);
    Node* current = set->buckets[hashIndex];
    
    while (current != NULL) 
    {
        if (current->key == key) 
        {
            return current->index;
        }

        current = current->next;
    }

    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int* result = (int*)malloc(2 * sizeof(int));
    HashSet* set = createHashSet();

    for (int i = 0; i < numsSize; i++)
    {
        int complement = target - nums[i];
        
        int complementIndex = search(set, complement);

        if (complementIndex != -1) 
        {
            result[0] = complementIndex;
            result[1] = i;
            break;
        }

        insert(set, nums[i], i, i);
    }

    *returnSize = 2;
    return result;
}