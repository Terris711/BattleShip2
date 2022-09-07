#ifndef LINKEDLIST_H

    #define LINKEDLIST_H

    /* Create Doubly Linked List's Node */
    typedef struct ListNode
    {
        void* value;
        struct ListNode* next;
        struct ListNode* prev;
    } ListNode;

    /* Create Doubly Linked List */
    typedef struct
    {
        ListNode* head;
        ListNode* tail;
        int count;
    } LinkedList;


    typedef char* (*printListFunc) (void* );

    typedef void (*freeFunc) (void* );


    LinkedList* createLinkedList();

    
    void insertFirst( LinkedList* list, void* addValue);
    void insertLast( LinkedList* list, void* addValue);


    void* removeFirst( LinkedList* list);
    void* removeLast( LinkedList* list);

    void printLinkedList( LinkedList* list, printListFunc* printList);
    void freeLinkedList( LinkedList* list, freeFunc* freeValue);

#endif

