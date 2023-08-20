#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define HASH_SIZE 10000

typedef struct Node {
    char key;
    int count;
    struct Node* next;
} Node;

typedef struct
{
    Node* hashArray[HASH_SIZE];
} HashSet;

int hashCode(char key)
{
    return key % HASH_SIZE;
}

HashSet* createHashSet()
{
    HashSet* set = (HashSet*)malloc(sizeof(HashSet));
    
    for(int i = 0; i < HASH_SIZE; i++)
    {
        set->hashArray[i] = NULL;
    }
    
    return set;
}

Node* contains(HashSet* set, char key) 
{
    int hashValue = hashCode(key);
    Node* node = set->hashArray[hashValue];

    while (node != NULL) 
    {
        if (node->key == key) 
        {
            return node;
        }

        node = node->next;
    }

    return NULL; 
}

void add(HashSet* set, char key) 
{
    int hashValue = hashCode(key);
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->key = key;
    newNode->next = set->hashArray[hashValue];
    set->hashArray[hashValue] = newNode;
}


bool isAnagram(char *s, char *t) 
{
    if (strlen(s) != strlen(t))
        return false;

    HashSet* charCount = createHashSet();

    for (int i = 0; s[i] != '\0'; i++)
    {
        int hashValue = hashCode(s[i]);
        Node* node = charCount->hashArray[hashValue];

        while (node != NULL) 
        {
            if (node->key == s[i]) 
            {
                node->count++;
                break;
            }

            node = node->next;
        }

        if (node == NULL)
        {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->key = s[i];
            newNode->count = 1;
            newNode->next = charCount->hashArray[hashValue];
            charCount->hashArray[hashValue] = newNode;
        }
    }

    for (int i = 0; t[i] != '\0'; i++)
    {
        int hashValue = hashCode(t[i]);
        Node* node = charCount->hashArray[hashValue];

        while (node != NULL) 
        {
            if (node->key == t[i]) 
            {
                node->count--;
                if (node->count < 0)
                {
                    return false;
                }
                break;
            }

            node = node->next;
        }

        if (node == NULL)
        {
            return false;
        }
    }

    return true;
}
