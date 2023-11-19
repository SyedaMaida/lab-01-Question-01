// #include <stdio.h>
// #include <stdlib.h>
// // Question:01
// struct Contact
// {
//  char name[20];
//  char email[20];
//  char phone[20];
// };
// int main ()
// {
//  int i = 0, numcontacts = 0;
//  int ind;
//  struct Contact *contact=NULL;
//  while (1)
//  {
//  printf("\n\nAddress book menu\nPress 1 to Enter a new contact\nPress 2 to delete a contact\nPress 3 to view Address book\nPress 4 to exit\nEnter your choice: ");
//  int choice;
//  scanf ("%d", &choice);
//  switch (choice)
// {
//     case 1:
//         numcontacts++;
//         contact=realloc(contact,numcontacts*sizeof(struct Contact));
//         printf ("\nEnter name of Contact %d: ", i + 1);
//         scanf ("%s", contact[i].name);
//         printf ("\nEnter email of Contact %d: ", i + 1);
//         scanf ("%s", contact[i].email);
//         printf ("\nEnter Phone no of Contact %d: ", i + 1);
//         scanf ("%s", contact[i].phone);
//         i++;
//         break;
//     case 2:
//         //int ind;
//         if (contact==NULL){
//         printf("Adress book is empty");
//         }
//         for (int j=0;j<i;j++){
//         printf("\nRecord of Adress %d\n",j+1);
//         printf("\nName of contact %d is %s",j+1,contact[j].name);
//         printf("\nEmail of contact %d is %s",j+1,contact[j].email);
//         printf("\nPhone no of contact %d is %s\n",j+1,contact[j].phone);
//         }
//         printf("\nEnter Adress no to be deleted: ");
//         scanf("%d",&ind);
//         if (ind<1|| ind>i){
//         printf("Invalid choice!!!");
//         break;
//          }
//         contact[ind-1]=contact[i-1];
//         i--;
//         contact=realloc(contact,i*sizeof(struct Contact));
//         break;
//     case 3:
//         if (contact==NULL){
//         printf("\nAdress book is empty");
//         }
//         for (int j=0;j<i;j++){
//         printf("\n\nRecord of Adress %d\n",j+1);
//         printf("\nName of contact %d is %s",j+1,contact[j].name);
//         printf("\nEmail of contact %d is %s",j+1,contact[j].email);
//         printf("\nPhone no of contact %d is %s",j+1,contact[j].phone);
//         }
//         break;
//     case 4:
//         free(contact);
//         printf("\nExiting Program....");
//         return 0;
//         default:
//         printf("Invalid choice! Please enter again...");
//         break;
// }
//  }
//  return 0;
//  } 

//  Question#02
// // Define a Node structure for a singly linked list
// struct Node {
//     int data;
//     struct Node* next;
// };

// // Function prototypes
// struct Node* mergeSortedLists(struct Node* list1, struct Node* list2);
// void insertNode(struct Node** head, int data);
// void displayList(struct Node* head);

// int main() {
//     // Creating the first sorted linked list: 1 -> 3 -> 5 -> 7
//     struct Node* list1 = NULL;
//     insertNode(&list1, 1);
//     insertNode(&list1, 3);
//     insertNode(&list1, 5);
//     insertNode(&list1, 7);

//     // Creating the second sorted linked list: 2 -> 4 -> 6 -> 8
//     struct Node* list2 = NULL;
//     insertNode(&list2, 2);
//     insertNode(&list2, 4);
//     insertNode(&list2, 6);
//     insertNode(&list2, 8);

//     // Merging the two sorted linked lists
//     struct Node* mergedList = mergeSortedLists(list1, list2);

//     // Displaying the merged sorted linked list
//     printf("Merged Sorted Linked List:\n");
//     displayList(mergedList);

//     return 0;
// }

// // Function to merge two sorted linked lists
// struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
//     struct Node* mergedList = NULL;
//     struct Node* current = NULL;

//     // Traverse both lists until one of them becomes empty
//     while (list1 != NULL && list2 != NULL) {
//         if (list1->data < list2->data) {
//             insertNode(&mergedList, list1->data);
//             list1 = list1->next;
//         } else {
//             insertNode(&mergedList, list2->data);
//             list2 = list2->next;
//         }
//     }

//     // If there are remaining nodes in list1, append them to the merged list
//     while (list1 != NULL) {
//         insertNode(&mergedList, list1->data);
//         list1 = list1->next;
//     }

//     // If there are remaining nodes in list2, append them to the merged list
//     while (list2 != NULL) {
//         insertNode(&mergedList, list2->data);
//         list2 = list2->next;
//     }

//     return mergedList;
// }

// // Function to insert a node with given data at the end of the list
// void insertNode(struct Node** head, int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     if (newNode == NULL) {
//         printf("Memory allocation failed. Exiting...\n");
//         exit(EXIT_FAILURE);
//     }

//     newNode->data = data;
//     newNode->next = NULL;

//     if (*head == NULL) {
//         *head = newNode;
//     } else {
//         struct Node* temp = *head;
//         while (temp->next != NULL) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
// }

// // Function to display the linked list
// void displayList(struct Node* head) {
//     struct Node* current = head;
//     while (current != NULL) {
//         printf("%d -> ", current->data);
//         current = current->next;
//     }
//     printf("NULL\n");
// }
//Question:03
#include <stdio.h>
#include <stdlib.h>

// Define a Node structure for a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
int* convertListToArray(struct Node* head, int* size);
void insertNode(struct Node** head, int data);
void displayList(struct Node* head);

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    struct Node* linkedList = NULL;
    insertNode(&linkedList, 1);
    insertNode(&linkedList, 2);
    insertNode(&linkedList, 3);
    insertNode(&linkedList, 4);
    insertNode(&linkedList, 5);

    // Displaying the original linked list
    printf("Original Linked List:\n");
    displayList(linkedList);

    // Converting the linked list to an array
    int size;
    int* array = convertListToArray(linkedList, &size);

    // Displaying the converted array
    printf("Converted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the allocated memory for the array
    free(array);

    return 0;
}

// Function to convert a linked list to an array
int* convertListToArray(struct Node* head, int* size) {
    // Count the number of nodes in the linked list
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    // Allocate memory for the array
    int* array = (int*)malloc(count * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    // Copy data from linked list to array
    current = head;
    for (int i = 0; i < count; i++) {
        array[i] = current->data;
        current = current->next;
    }

    // Set the size of the array
    *size = count;

    return array;
}

// Function to insert a node with given data at the end of the list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
//Question:04
