#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* trocaLista(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* newHead = head->next;
    struct ListNode* prev = NULL;
    struct ListNode* current = head;

    while (current != NULL && current->next != NULL) {
        struct ListNode* nextPair = current->next->next;
        struct ListNode* second = current->next;

        second->next = current;
        current->next = nextPair;

        if (prev != NULL) {
            prev->next = second;
        }

        prev = current;
        current = nextPair;
    }

    return newHead;
}

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}


void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}


int main() {

    int values[] = {1, 2, 3, 4};
    int n = sizeof(values) / sizeof(values[0]);


    struct ListNode* head = createNode(values[0]);
    struct ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = createNode(values[i]);
        current = current->next;
    }


    head = trocaLista(head);


    printList(head);

    return 0;
}