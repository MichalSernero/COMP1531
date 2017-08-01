#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _node *nodePointer;

typedef struct _node {
    nodePointer next;
    int data;
} node;

typedef struct _list *List;

typedef struct _list {
    nodePointer first;
} list;

void testInterleave();
void testInsertAt();
void testReverse();
void freeList(List l);
void interleave(List l1, List l2);
void insertAt(List l, int pos, int val);
void reverse(List l); 

int main(int argc, char *argv[]) {
    printf("Testing interleave()\n");
    testInterleave();
    
    printf("Testing insertAt()\n");
    testInsertAt();
    
    printf("Testing reverse()\n");
    testReverse();

    return EXIT_SUCCESS;    
}

void testInterleave() {
    //first list
    List l1 = malloc(sizeof(list));

    //First node
    l1->first = malloc(sizeof(node));
    l1->first->data = 3;

    //Second node
    l1->first->next = malloc(sizeof(node));
    l1->first->next->data = 5;

    //Third node
    l1->first->next->next = malloc(sizeof(node));
    l1->first->next->next->data = -2;
    l1->first->next->next->next = NULL;

    //second list
    List l2 = malloc(sizeof(list));
    
    //first node
    l2->first = malloc(sizeof(node));
    l2->first->data = 102;

    //second node
    l2->first->next = malloc(sizeof(node));
    l2->first->next->data = -100;

    //third node
    l2->first->next->next = malloc(sizeof(node));
    l2->first->next->next->data = 3;
    l2->first->next->next->next = NULL;

    printf("Testing interleave on lists of size 3\n");
    interleave(l1, l2);

    assert(l2->first == NULL);
    assert(l1->first->data == 3);
    assert(l1->first->next->data == 102);
    assert(l1->first->next->next->data == 5);
    assert(l1->first->next->next->next->data == -100);
    assert(l1->first->next->next->next->next->data == -2);
    assert(l1->first->next->next->next->next->next->data == 3);
    assert(l1->first->next->next->next->next->next->next == NULL);

    printf("Passed test on list of size 3\n");

    freeList(l1);
    freeList(l2);

    printf("Testing interleave on lists of size 0\n");

    interleave(l1, l2);

    assert(l1->first == NULL);
    assert(l2->first == NULL);

    printf("Passed tests on list of size 0\n");

    free(l1);
    free(l2);
}

void testInsertAt() {
    List l = malloc(sizeof(list));
    l->first = NULL;

    insertAt(l, 1000, 10);
    assert(l->first->data == 10);
    assert(l->first->next == NULL);

    insertAt(l, 0, -10);
    assert(l->first->data == -10);
    assert(l->first->next->data == 10);
    assert(l->first->next->next == NULL);

    insertAt(l, 1, 7);
    assert(l->first->data == -10);
    assert(l->first->next->data == 7);
    assert(l->first->next->next->data == 10);
    assert(l->first->next->next->next == NULL);

    insertAt(l, 2, 1);
    assert(l->first->data == -10);
    assert(l->first->next->data == 7);
    assert(l->first->next->next->data == 1);
    assert(l->first->next->next->next->data == 10);
    assert(l->first->next->next->next->next == NULL);

    freeList(l);    
    free(l);
}

void testReverse() {
    //first list
    List l1 = malloc(sizeof(list));

    //First node
    l1->first = malloc(sizeof(node));
    l1->first->data = 3;

    //Second node
    l1->first->next = malloc(sizeof(node));
    l1->first->next->data = 5;

    //Third node
    l1->first->next->next = malloc(sizeof(node));
    l1->first->next->next->data = -2;
    l1->first->next->next->next = NULL;
    
    reverse(l1);

    printf("Testing reverse on a list of size 3\n");
    assert(l1->first->data == -2);
    assert(l1->first->next->data == 5);
    assert(l1->first->next->next->data == 3);
    assert(l1->first->next->next->next == NULL);
    printf("Testing reverse on a list of size 3\n");

    freeList(l1);

    printf("Testing reverse on a list of size 0\n");
    reverse(l1);
    assert(l1->first == NULL);
    printf("Test on list of size 0 passed\n");

    free(l1);
}

//Implement a function which given a list frees all nodes
//but leaves the list struct intact. l->first must be null
//after this function ends.
void freeList(List l) {
}

//Implement a function which interleaves two lists of equal length.
//l1 should point to the new interleaved list and l2 should point to null.
//the first element of l1 should be the first element of the new interleaved list
//For example an input of:
//l1: 1->3->5->X
//l2: 2->4->6->X
//Should finish with:
//l1: 1->2->3->4->5->6->X
//l2: X
void interleave(List l1, List l2) {
}

//Implement a function which inserts a node at position pos into a given
//list which holds the given value. If pos runs off the linked list
//then the newnode should be appended to the end of the list.
//For example an input of:
//l1: 0->1->2->3->4->X
//val: 12
//pos: 3
//Should output:
//l1: 0->1->2->12->3->4->X

//an input of:
//l1: 0->1->2->X
//val: 100
//pos: 10
//Should output:
//l1: 0->1->2->100->X
void insertAt(List l, int pos, int val) {
}

//HARD:
//Implement a function which reverses all the links in a list.
//For example given:
//l1: 0->1->2->3->4->X
//Should output:
//l1: 4->3->2->1->0->X
void reverse(List l) {

}
