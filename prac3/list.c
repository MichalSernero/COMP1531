#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "list.h"

Lnode * makeNode( int data ){
  Lnode *new_node = (Lnode*)malloc(sizeof(Lnode));
  if( new_node == NULL ) {
    printf("Error: memory allocation failed\n");
    exit(1);
  }
  new_node->data = data;
  new_node->next = NULL;
  return( new_node);
}


Lnode * append( Lnode *new_node, Lnode *head ){

  if( head == NULL ) {
    head = new_node;
  }
  else {
    Lnode *current = head;
    // find the tail of the list
    while( current->next != NULL ) {
      current = current->next;
    }
    current->next = new_node;
  }
  return( head );
}

void printList( Lnode *head ){

  Lnode *node = head;

  // traverse the list printing each node in turn
  while( node != NULL ) {
    printf("->%d", node->data );
    node = node->next;
  }
  printf("\n");
}

void freeList( Lnode *head ){

  Lnode *node = head;
  Lnode *tmp;

  while( node != NULL ) {
    tmp = node;
    node = node->next;
    free(tmp);
  }
}

Lnode *backToFront (Lnode head){
	Lnode cur = head;
	Lnode prev = NULL;

	if (cur->head == NULL || cur->next == NULL){
		return head;
	}

	while(cur->next != NULL){
		prev = cur;
		cur = cur->next;
	}
	
	cur->next = head;
	prev = NULL;
