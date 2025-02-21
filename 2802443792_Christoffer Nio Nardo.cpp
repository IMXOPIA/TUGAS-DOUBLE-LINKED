#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int x;
    struct tnode* next;
    struct tnode* prev;
} *head, *tail;

void push_front(int value) {
    struct tnode* node = (struct tnode*)malloc(sizeof(struct tnode));
    node->x = value;
    node->prev = NULL;
    
    if (head == NULL) {
        head = tail = node;
        node->next = NULL;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }
}

void push_back(int value) {
    struct tnode* node = (struct tnode*)malloc(sizeof(struct tnode));
    node->x = value;
    node->next = NULL;
    
    if (head == NULL) {
        head = tail = node;
        node->prev = NULL;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}

void push_mid(int value, int searchKey) {
    struct tnode* node = (struct tnode*)malloc(sizeof(struct tnode));
    node->x = value;
    
    if (head == NULL) {
        head = tail = node;
        node->next = NULL;
        node->prev = NULL;
    } else {
        struct tnode* curr = head;
        while (curr != NULL) {
            if (curr->x == searchKey) {
                if (curr == tail) {
                    push_back(value);
                } else {
                    node->next = curr->next;
                    node->prev = curr;
                    curr->next->prev = node;
                    curr->next = node;
                }
                return;
            }
            curr = curr->next;
        }
        printf("Data %d is not found in the linked list\n", searchKey);
    }
}

void delete_back() {
    if (tail == NULL) {
        printf("There is no data\n");
        return;
    } else {
        if (head == tail) {
            printf("Cannot delete the last node because there is only one node.\n");
        } else {
            struct tnode* del = tail;
            tail = tail->prev;
            tail->next = NULL;
            free(del);
        }
    }
}

void delete_mid(int value) {
    if (head == NULL) {
        printf("There is no data\n");
        return;
    } else {
        struct tnode* curr = head;
        while (curr != NULL) {
            if (curr->x == value) {
                if (curr == head || curr == tail) {
                    printf("Cannot delete the first or last node.\n");
                } else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    free(curr);
                }
                return;
            }
            curr = curr->next;
        }
        printf("Node with value %d not found in the list\n", value);
    }
}

void printList() {
    if (head == NULL) {
        printf("List kosong\n");
        return;
    }
    
    struct tnode* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->x);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    printf("Double Linked List\n");
    
    push_back(13);
    push_back(1);
    push_back(3);
    push_back(99);
    printList();  
    
    delete_back();
    printList();  
    
    push_mid(15, 3);
    printList(); 
    delete_mid(3);
    printList(); 
    delete_back();
    printList();  
    
    return 0;
}
