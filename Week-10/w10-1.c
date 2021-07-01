//Aman Sharma
//20EC10007
#include <stdio.h>
#include <stdlib.h>

struct Node{        //defining structure for nodes
    int data;
    struct Node *next;
};

struct Node *insertll(struct Node *r, int value){    //Function that inserts in ascending order if no duplicate is found
    struct Node *p, *q, *new;
    new = (struct Node *)malloc(sizeof(struct Node));//Make a new node with given inputs
    new->data = value;
    new->next = NULL;
    p = r;                                           //We'll use these pointers(p, q) to traverse through the linked list
    q = p;
    while (p != NULL){                               //Loop throughout the list, i.e., until list is terminated
        if (p->data==value){    //this case checks for duplicates
            free(new);          //memory is freed without adding new node
            return r;           //original linked list is returned
        }
        if (p->data > value){ 
            //CASE: when leftmost element is greater than value, then we insert at start of ll
            if (p == r){
                new->next = r;  //Linking node to head of existing list
                return new;     //Returning new head
            }

            //CASE: insertion in the middle
            new->next = p;      /* insert before p */
            q->next = new;      //Make both the connections to and from ll
            return r;           //Return the original head as we inserted in the middle, so head remains same
        }
        q = p;
        p = p->next;
    }

    //CASE: Linked list is empty, this won't be acheived as we've covered this case in main() seperately but still written here for completion of cases
    if (r == NULL)
        return new; /* first time */

    //No element bigger is found throughout the list, meaning we insert at the end
    else
        q->next = new;      /* insert at end */
    return r;               //return the linked list with term added
}




void printll(struct Node *head){    //Function that prints a linked list
    struct Node *ptr = head;
    while (ptr!=NULL){              //Traverses throughout the ll
        printf("%d ", ptr->data);   //Prints the data stored
        ptr = ptr->next;
    }
    printf("[end]");
    return;
}

void deleteList(struct Node* head)  //Function that frees allocated memory for the ll at the end
{
   struct Node* current = head;
   struct Node* next;
 
   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }
   head = NULL;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));   //Initialise pointer to head and allocate space for head
    printf("Enter nonzero elements (0 to stop): ");
    int j;
    scanf("%d", &j);
    if (j==0){ //If the first input value is 0 itself
        head = NULL;                                    //The head is null as linked list is terminated
        printf("List elements in increasing order = ");
        printll(head);                                  //We print the empty list
        deleteList(head);                               //We free the memory
        return 0;
    }
    head->data = j;                                     //Since first input is not zero, we insert it to the linked list as the head as it is the only value
    head->next = NULL;
    while (j != 0){                                     //Loop until the user enters 0
        scanf("%d", &j);
        if (j!=0){                                      //We insert element using the defined function
            head = insertll(head, j);
        }
    }
    printf("List elements in increasing order = ");
    printll(head);                                      //Printing the ll
    deleteList(head);                                   //Clearing memory allocated to ll
    return 0;
}