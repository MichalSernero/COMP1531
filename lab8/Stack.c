#include "Stack.h"
#include "Pancake.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
struct stack {
    int numPancakes;
    Pancake array[MAX_PANCAKES];
};

Stack createStack(void) {
	// TO DO
	Stack s = malloc(sizeof(struct stack));
	if(s == NULL){
		printf("Not enough memory aka NO PANCAKE STACKS HOW DARE YOU!");
		exit(1);
	}
	s->numPancakes = 0;
	return s;
}
// if stack is already full, do nothing
void addPancake(Stack s, char *topping, int size) {
	// TO DO
	assert(s != NULL);
	
	if(s->numPancakes != 40){
		s->array[s->numPancakes] = bake(topping, size);
		(s->numPancakes)++;
	
	}
}
// if stack is already empty, do nothing
void eatPancake(Stack s){
	// TO DO
	assert(s != NULL);
	if(s->numPancakes != 0){
		eat(s->array[s->numPancakes - 1]);
		(s->numPancakes)--;
	}
}

int numPancakes(Stack s) {
	// TO DO
	return s->numPancakes;
}

int totalSize(Stack s) {
	// TO DO
	int sizeTotal = 0;
	int count = 0;
	while(count < s->numPancakes){
		//getSize(s->array[count]) += sizeTotal;
		sizeTotal += getSize(s->array[count]);
		count++;
	}
	return sizeTotal;
}

void printToppings(Stack s) {
	// TO DO
	int count = s->numPancakes;
	while(count >= 1){
		printf("%s\n", getTopping(s->array[count - 1]));
		count--;
	}
}


void consumeStack(Stack s) {
	// TO DO
	int count = 0;
	while(count < s->numPancakes){
		eat(s->array[count]);
		count++;
	}
	free(s);
}
