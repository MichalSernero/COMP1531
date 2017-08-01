#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

#define FALSE -1
#define TRUE 0
struct node{
  int val;
  Lnode next;  
};


struct list{
    Lnode head;
    int num_nodes;
};

Lnode new_node(int val){
    Lnode new = malloc(sizeof(struct node));
    if(new == NULL){
        printf("Out of memory:(\n");
        exit(1);
    }
    new->val = val;
    new->next = NULL;
    return new;
}
List newList(void){
    List new = malloc(sizeof(struct list));
    if(new == NULL){
        printf("Out of memory:(\n");
        exit(1);
    }
    new->head = NULL;
    new->num_nodes = 0;
    return new;
}

void append(List l, int val){
    assert(l != NULL);
    Lnode cur = l->head;
    Lnode new = new_node(val);
    if(cur == NULL){
        l->head = new;
    }else{
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = new;
        
    }
    l->num_nodes++;
}

void printList(List l){
    assert(l!= NULL);
    Lnode cur = l-> head;
    while(cur != NULL){
        printf("[%d]->",cur->val);
        cur = cur->next;
    }
    printf("X\n");
}


void destroy(List l){
    assert(l!= NULL);
    Lnode cur = l->head;
    Lnode prev = NULL;
    // free every single element of the list
    while(cur!= NULL){
        prev = cur;
        cur = cur->next;
        free(prev);
    }
    // free the list structure itself
    free(l);
}
int num_nodes(List l){
    return l->num_nodes;
}
//Given a linked list print it out in reverse
//Do not reverse original list
//Example:
//Given linked list [1]->[2]->[3]->X
//print_reverse output: [3]->[2]->[1]->X
void print_reverse(List l){
	assert(l != NULL);
    Lnode cur = l->head;
	int Reverse[l->num_nodes];
	int i = l->num_nodes-1;
	while(cur != NULL){
		Reverse[i] = cur->val;
        cur = cur->next;
		i--;
	}
		for(i=0; i < l->num_nodes; i++){
			printf("[%d]->",Reverse[i]);
		}
	printf("X\n");
}

//Given a linked list create a new list containing only unique 
//elements of the current list. The order of the elements should remain 
// the same as in original linked list. Do not modify the original list.
//Example
//Input: 1->1->2->3->3->3->0->X
//Output:1->2->3->0->X
List extract_unique(List l){
	assert(l != NULL);
	List new = newList();
	Lnode cur = l->head;
	Lnode new_cur = new->head;
	int temp;
	int flag = FALSE;
	if(l->head != NULL){
		if(cur->next == NULL){
			append(new, cur->val);
		}
		else{
			while(cur != NULL){
				temp = cur->val;
				while(flag == FALSE && new_cur != NULL){
					if(new_cur->val == temp){
						flag = TRUE;
					}
					new_cur = new_cur->next;
				}
				if(flag == FALSE){
					append(new, temp);
				}
			flag = FALSE;
			cur = cur->next;
			new_cur = new->head;
			}
		}
	}
    return new;
}

List reverseList(List l, Lnode head){
	Lnode cur = head;
	Lnode prev = NULL;
	Lnode before;
	if(cur != NULL){
		prev = cur;
		cur = cur->next;
		prev->next = NULL;
		while(cur->next != NULL){
			before = prev;
			prev = cur;
			cur = cur->next;
			prev->next = before;
		}
			cur->next = prev;
	}
	return l;
}






