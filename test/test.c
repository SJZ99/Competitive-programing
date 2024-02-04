#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define HASH_SIZE 1000000
#define ll long long int

// f-heap
typedef struct node {
    ll key, val;
    struct node *l, *r, *pa, *child;
    bool childCut;
    int degree;
} Node;

// hash table
typedef struct listNode {
    struct listNode* next;
    ll key, val;
    Node* node;
} ListNode;

int hashSize = 0;
ListNode* ht[HASH_SIZE];

unsigned int hash(ll key, ll value) {
    unsigned int h = ((key << 8) ^ key);
    h <<= 4;
    h ^= value;
    h %= HASH_SIZE;
    return h;
}

void insertHash(Node* fnode) {
    ll key = fnode->key;
    ll value = fnode->val;

    int h = hash(key, value);

    ListNode* node = calloc(1, sizeof(ListNode));
    node->key = key;
    node->val = value;
    node->node = fnode;

    if(ht[h] != NULL) {
        ListNode* curr = ht[h];
        while(curr->next != NULL) {
            // printf("%d\n", curr->key);
            curr = curr->next;
        }

        curr->next = node;
    } else {
        ht[h] = node;
    }
    hashSize++;
}

Node* popHash(ll key, ll value) {
    int h = hash(key, value);
    ListNode* curr = ht[h];
    ListNode* pre = curr;
    while(curr != NULL && (curr->key != key || curr->val != value) && curr->next != NULL) {
        pre = curr;
        curr = curr->next;
    }

    if(curr->key == key && curr->val == value) {

        Node* fn = curr->node;
        curr->node = NULL;

        pre->next = curr->next;

        free(curr);
        hashSize--;
        return fn;
    } else {
        return NULL;
    }
}

int main(void) {
    Node a;
    a.key = 
    insertHash()
    return 0;
}