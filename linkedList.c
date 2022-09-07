#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

/* create a pointer to a linked list, create memory, set head and tail to null and count(number of node) tes 0 */

LinkedList* createLinkedList()
{
    /*Create a new list*/
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));

    list -> head = NULL;
    list -> tail = NULL;
    list -> count = 0;

    return list;
}


void insertFirst( LinkedList* list, void* addValue)
{
    /* Create a new node*/
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    /*Connect to the previous head of the list, the head's previous is set as new node */
    ListNode* prevHead;

    /* Set Node*/
    newNode -> value = addValue;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    if (list -> head == NULL)
    {
        /* Base Case: if the linked list is empty, the new node will be the head & tail */
        list -> head = newNode;
        list -> tail = newNode;
    }
    else
    {
        /* if the list already has nodes */
        newNode -> next = list -> head;
        prevHead = newNode -> next; 
        prevHead -> prev = newNode; /* Update the previous of head node */
        list -> head = newNode; /*Set the head to new node*/
    }

    list -> count += 1;

}


void insertLast( LinkedList* list, void* addValue)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode)); /* Create new node to insert */
    
    /*The previous of the tail will be set as new Node*/
    ListNode* prevTail;

    newNode -> value = addValue;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    if (list -> head == NULL)
    {
        /* Base Case: if the linked list is empty, the new node will be the head & tail */
        list -> head = newNode;
        list -> tail = newNode;
    }
    else
    {
        newNode -> prev = list -> tail;
        prevTail = newNode -> prev;
        prevTail -> next = newNode;

        list -> tail = newNode;
    }

    list -> count += 1;
}


void* removeFirst( LinkedList* list)
{
    void* delNode;

    ListNode* prevHead;

    if (list -> count == 0)
    {
        delNode = NULL;
    }
    else if( list -> count == 1) /* The list has only one element */
    {
        delNode = (list -> head) -> value;
        prevHead = list -> head;

        list -> head = NULL;
        list -> tail = NULL;
        free(prevHead);
    }
    else
    {
        delNode = (list -> head) -> value;
        prevHead = list -> head;

        list -> head = (list -> head) -> next;
        list -> head -> prev = NULL;
        free(prevHead);
    }

    list -> count -= 1;

    return delNode;
}

void* removeLast( LinkedList* list)
{
    void* delNode;

    ListNode* prevTail;

    if(list -> count == 0)
    {
        delNode = NULL;
    }
    else if (list -> count == 1)
    {
        delNode = (list -> tail) -> value;
        prevTail = list -> tail;

        list -> head = NULL;
        list -> tail = NULL;
        free(prevTail);
    }
    else
    {
        delNode = (list -> tail) -> value;
        prevTail = list -> tail;

        list -> tail = (list -> tail) -> prev;
        list -> tail -> next = NULL;
        free(prevTail);

    }
    
    list -> count -= 1;

    return delNode;
}



void printLinkedList( LinkedList* list, printListFunc* printList)
{
    ListNode* curNode;
    if (list -> count == 0)
    {
        printf(" Linked List is empty\n");
    }
    else
    {
        curNode = list -> head;
        printf( "[" );
        while (curNode != NULL)
        {
            if (curNode -> next == NULL)
            {
                /* Current Node is the last node*/
                printf(" %s ]\n", (*printList) (curNode -> value));
            }
            else
            {
                /* After current node, there are more nodes to go */
                printf(" %s,", (*printList)(curNode -> value));
            }
            curNode = curNode -> next;
        }
    }
}


void freeLinkedList( LinkedList* list, freeFunc* freeValue)
{
    ListNode* curNode; /* Current Node is the node that need to free */
    ListNode* nextNode;

    if (list -> count > 0)
    {
        curNode = list -> head;
        while (curNode != NULL)
        {
            nextNode = curNode -> next;
            (*freeValue) (curNode -> value);
            free (curNode);
            curNode = nextNode;
        }
    }

    free( list );


}

char* printElement(void* inp)
{
    return inp;
}

/*int main()
{  
   LinkedList* list = NULL;
   printListFunc* printList = printElement;
   
   
   list = createLinkedList();
   insertFirst(list, "1");
   insertLast(list, "3");
   insertLast(list, "4");
   insertLast(list, "5");
   removeFirst(list);
   removeLast(list);

   printLinkedList(list, &printList);
   


   return 0;
}
*/
