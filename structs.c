#include <stdio.h>
#include <stdlib.h>

// int node
typedef struct node {
    int value;
    struct node *next;
} node;

// char node
typedef struct _node {
    char value;
    struct _node *next;
} _node;

void print_node(node *ptr) { // put in the head of the list
    while (ptr != NULL) {
        printf("%d -> ", ptr->value);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

node *add(node *ptr, int value) { // if the added node is a new node, return a pointer pointing to the new node. Otherwise, return a pointer pointing to the node before the last node
    node *new_node = malloc(sizeof(node));

    // malloc is unsucessful
    if (new_node == NULL) {
        return NULL;
    }

    // initialize the node
    new_node->value = value;
    new_node->next = NULL;

    if (ptr == NULL) {
        return new_node;
    }

    while (ptr != NULL && ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    return ptr;
}

// Another way to add node
node *add(node *head, int _value) { // add a node and return the head of the node
    node *new_node = malloc(sizeof(node)); // allocate memory to store the new node
    new_node->value = _value; // set the int value of the new node
    new_node->next = NULL; // end of the list

    // If new node is the first node, the first node is the head
    if (head == NULL) {
        head = new_node;
        return new_node;
    }

    // Else there are pre-existing nodes
    node *temp_ptr = head; // move this to go through the list

    // Now go to the end of the list
    while (temp_ptr->next != NULL) {
        temp_ptr = temp_ptr->next;
    }

    // Now change the last node
    temp_ptr->next = new_node;
    return head;
}

int get_size_of_list(node *head) { // put in the head of the list
    int count = 0;
    while (head != NULL) {
        head = head->next;
        count++;
    }
    return count;
}

void free_linked_list(node *head) { // free linked list
    node *curr = head;

    while (curr != NULL) {
        head = head->next;
        free(curr);
        curr = head;
    }
}

int main() {

}