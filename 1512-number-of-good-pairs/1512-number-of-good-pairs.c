#include<stdlib.h>

#define SIZE 1000

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct HashSet 
{
    Node* buckets[SIZE];
} HashSet;

int hashIndex(int key)
{
    return key % SIZE;
}

HashSet* createHashSet()
{
    HashSet* set = (HashSet*)malloc(sizeof(HashSet));

    for(int i = 0; i < SIZE; i++)
    {
        set->buckets[i] = NULL;
    }

    return set;
}

void insert(HashSet* set, int key, int value)
{
    Node* item = (Node*)malloc(sizeof(Node));
    item->key = key;
    item->value = value;
    item->next = NULL;

    int index = hashIndex(key);

    if(set->buckets[index] == NULL)
    {
        set->buckets[index] = item;
    }
    else
    {
        Node* current = set->buckets[index];

        while(current->next != NULL)
        {
            current = current->next;
        }

        current->next = item;
    }
}

int contains(HashSet* set, int key)
{
    int index = hashIndex(key);
    Node* current = set->buckets[index];

    int sum = 0;

    while(current != NULL)
    {
        if(current->key == key)
        {
            sum++;
        }

        current = current->next;
    }

    return sum;
}

int numIdenticalPairs(int* nums, int numsSize)
{
    HashSet* set = createHashSet();
    int result = 0;

    for(int i = 0; i < numsSize; i++)
    {
        result += contains(set, nums[i]);
        insert(set, nums[i], i);
    }

    return result;
}