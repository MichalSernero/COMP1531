//List.c
typedef struct _node *nodePointer;
     
typedef struct _node {
    int data;
    nodePointer next;
} node;
     
typedef struct _list {
    nodePointer first;
} list;
     
List newList (void) {
    List new = malloc (sizeof (struct _list));
    assert (new != NULL);
     
    new->first = NULL;
    return new;
}
 
//ADD MORE FUNCTIONS
 

//List.h
 
 
typedef struct _list *List;
 
//create a new list
List newList (void);
Complete these steps with a linked list. It is best to have each step as a separate function.

 

 

Step 1:

Make a list with nodes 2, 3, 4, ..., 18, 19, 20.


 

Step 2:

Add 1 to the beginning of the list


 

Step 3:

Move all the numbers with 2 digits to the front, preserve the ascending order for double digits


 

Step 4:

Remove the minimum number.


 

Step 5:

Remove the number at the end of the list.


 

Step 6:

Separate the odd numbers below 14 to another list.


 

Step 7:

Reverse the larger list, (if they are the same size, then reverse the new list made in Step 6.)


 

Step 8:

Free the list that was not reversed.


 

Step 9 (Challenge):

Make the remaining list follow this pattern.
->1->2->3->4->5->6->7->8->9->10->NULL
to
->1->3->2->4->6->5->7->9->8->10->NULL
(Start with the first node, jump to the node 2 places after the current node, backtrack to the previous node, Jump to the node 2 places after the current node TWICE, backtrack to the previous node until it is about to go to NULL. If it is about to go to NULL, append the remaining nodes then point to NULL.


Step 10 (Extra) :

Change the 1st question to Make a list with nodes 2, 3, 4, ..., 25, 26, 27. Steps 2-9 should not be modified if it was correct.
