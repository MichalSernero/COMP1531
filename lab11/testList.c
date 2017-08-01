#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

void test_print_reverse(void);
void test_extract_unique(void);

void reverse_one(void);
void reverse_empty(void);
void reverse_many(void);

void unique_empty(void);
void unique_one(void);
void unique_consecutive(void);
void unique_many(void);

int main(void){
    //call individual test functions
    test_print_reverse();
    test_extract_unique();

    return 0;
}


void test_print_reverse(void){
    reverse_one();
	reverse_empty();
	reverse_many();
    //add any additional functions to test your implementation here
}

void rest_extract_unique(void){
	unique_empty();
	unique_one();
	unique_consecutive();
	unique_many();
}

void reverse_one(void){
    printf("Testing print_reverse with 1 element\n");
    List new = newList();
    append(new, 0);
    printf("Expected output:\n");
    printf("[0]->X\n");
    printf("Your output:\n");
    print_reverse(new);
    destroy(new);
    printf("=========================\n");
}

void reverse_empty(void){
	printf("Testing print_reverse with 0 elements\n");
	List new = newList();
	printf("Expected output:\n");
	printf("X\n");
	printf("Your output:\n");
	print_reverse(new);
	destroy(new);
	printf("=========================\n");
}

void reverse_many(void){
	printf("Testing print_reverse with many elements\n");
	List new = newList();
	append(new, 1);
	append(new, 2);
	append(new, 3);
	append(new, 4);
	append(new, 5);
	append(new, 6);
	printf("Expected output:\n");
    printf("[6]->[5]->[4]->[3]->[2]->[1]->X\n");
    printf("Your output:\n");
    print_reverse(new);
    destroy(new);
    printf("=========================\n");
}
//##################################################################
void test_extract_unique(void){
	unique_empty();
	unique_one();
	unique_consecutive();
	unique_many();
    //add any additional functions to test your implementation here
}

void unique_empty(void){
    printf("Testing extract_unique with empty list\n");
    List new = newList();
    List u = extract_unique(new);
    assert(num_nodes(new) == 0);
    assert(num_nodes(u) == 0);
    destroy(new);
    printf("Passed\n");
    printf("=========================\n");
}

void unique_one(void){
    printf("Testing extract_unique with one element\n");
    List new = newList();
	append(new, 0);
	printf("Expected output:\n");
	printf("[0]->X\n");
    printf("Your output: ");
    List u = extract_unique(new);
	printList(u);
    assert(num_nodes(new) == 1);
    assert(num_nodes(u) == 1);
    destroy(new);
    printf("Passed\n");
    printf("=========================\n");
}

void unique_consecutive(void){
    printf("Testing extract_unique with consecutive elements\n");
    List new = newList();
	append(new, 1);
	append(new, 2);
	append(new, 2);
	append(new, 3);
	append(new, 3);
	append(new, 3);
	append(new, 4);
	append(new, 4);
	append(new, 4);
	append(new, 4);
	printf("Expected output:\n");
	printf("[1]->[2]->[3]->[4]->X\n");
    printf("Your output: ");
    List u = extract_unique(new);
	printList(u);
    assert(num_nodes(new) == 10);
    assert(num_nodes(u) == 4);
    destroy(new);
    printf("Passed\n");
    printf("=========================\n");
}

void unique_many(void){
    printf("Testing extract_unique with repeating elements in list\n");
    List new = newList();
	append(new, 1);
	append(new, 2);
	append(new, 1);
	append(new, 2);
	append(new, 3);
	append(new, 2);
	append(new, 3);
	append(new, 4);
	append(new, 4);
	append(new, 3);
	printf("Expected output:\n");
	printf("[1]->[2]->[3]->[4]->X\n");
    printf("Your output: ");
    List u = extract_unique(new);
	printList(u);
    assert(num_nodes(new) == 10);
    assert(num_nodes(u) == 4);
    destroy(new);
    printf("Passed\n");
    printf("=========================\n");
}
