#include <stdio.h>
#include <stdlib.h>

 typedef struct node {
        int number;
        struct node* next;
    } node;
int main (int argc, char* argv[]) {
    node *head = NULL; // this is the start of the list

    for (int i = 0; i < argc; i++) {
        int number = atoi(argv[i]); // this is to convert the command line arguments which are strings into integers
        node *temp = malloc(sizeof(node));
        if (temp == NULL) {
            printf("Not enough Memeory\n");
            return 1;
        }
        temp->number = number;
        temp->next = head;
        head = temp;
    }
    node *ptr = head;
    while (ptr != NULL) {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
    ptr = head;
     while (ptr != NULL) {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}