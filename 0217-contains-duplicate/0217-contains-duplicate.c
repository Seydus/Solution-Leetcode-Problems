#include <stdbool.h>

#define HASH_SIZE 10000

typedef struct Node 
{
    int key;
    struct Node* next;
} Node;

typedef struct 
{
    Node* buckets[HASH_SIZE];
} HashSet;

int hash(int key) 
{
    return abs(key) % HASH_SIZE;
}

HashSet* createHashSet() 
{
    HashSet* set = (HashSet*)malloc(sizeof(HashSet));

    for (int i = 0; i < HASH_SIZE; i++) 
    {
        set->buckets[i] = NULL;
    }

    return set;
}

bool contains(HashSet* set, int key) 
{
    int hashValue = hash(key);
    Node* node = set->buckets[hashValue];

    while (node != NULL) 
    {
        if (node->key == key) 
        {
            return true;
        }

        node = node->next;
    }

    return false;
}

void add(HashSet* set, int key) 
{
    int hashValue = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->key = key;
    newNode->next = set->buckets[hashValue];
    set->buckets[hashValue] = newNode;
}

bool containsDuplicate(int* nums, int numsSize) 
{
    HashSet* set = createHashSet();

    for (int i = 0; i < numsSize; i++) 
    {
        if (contains(set, nums[i])) 
        {
            return true;
        }

        add(set, nums[i]);
    }

    return false;
}