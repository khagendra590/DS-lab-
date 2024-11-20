#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

void insertLeft(struct Node** head_ref, int target_data, int new_data) {
    struct Node* current = *head_ref;
    while (current != NULL) {
        if (current->data == target_data) {
            struct Node* newNode = createNode(new_data);
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev != NULL) {
                current->prev->next = newNode;
            } else {
                *head_ref = newNode;
            }
            current->prev = newNode;
            return;
        }
        current = current->next;
    }
    printf("Node with data %d not found.\n", target_data);
}
void deleteNode(struct Node** head_ref, int value) {
    struct Node* current = *head_ref;
    while (current != NULL) {
        if (current->data == value) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *head_ref = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
    printf("Node with data %d not found.\n", value);
}

void display(struct Node* node) {
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, data, target_data, new_data, delete_value;

    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insert(&head, data);
    }

    printf("Original list:\n");
    display(head);

    printf("Enter the value of the node to insert left of: ");
    scanf("%d", &target_data);
    printf("Enter the new data to insert: ");
    scanf("%d", &new_data);
    insertLeft(&head, target_data, new_data);
    printf("After inserting %d to the left of %d:\n", new_data, target_data);
    display(head);

    printf("Enter the value to delete: ");
    scanf("%d", &delete_value);
    deleteNode(&head, delete_value);
    printf("After deleting %d:\n", delete_value);
    display(head);

    return 0;
}
