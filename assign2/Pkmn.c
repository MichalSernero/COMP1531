#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "Pkmn.h"

const char * const TYPES[] = {
   "Bug",
   "Dark",
   "Dragon",
   "Electric",
   "Fairy",
   "Fighting",
   "Fire",
   "Flying",
   "Ghost",
   "Grass",
   "Ground",
   "Ice",
   "Normal",
   "Poison",
   "Psychic",
   "Rock",
   "Steel",
   "Water"};

// ADD YOUR CODE HERE - any extra typedefs and #defines you'd like to use

#define FOUND 0
#define CAPTURED 1

struct _list {
 	Pkmn head;
	Pkmn current;
	int total;
	int countTotal;
	
};

struct _pkmn {
	Pkmn head;
	Pkmn current;
   	int id;
	char * name;
	double height;
	double weight;
	int type1;
	int type2;
	int status;
	int evo1;
	int evo2;
	Pkmn next;
	
};

// ADD YOUR CODE HERE - any extra structs you'd like to use

// ADD YOUR CODE HERE - any extra helper functions you'd like to use from within this file

const char * getTypeString(int i) {
   return TYPES[i];
}

Pkmn createPkmn(int id, char * name, double height, double weight, int type1, int type2) {
   Pkmn new = malloc(sizeof(struct _pkmn));
	if(new == NULL){
		printf("Out of Memory.\n");
		exit(1);
	}
	
	new->id = id;
	new->name = strdup(name);
	new->height = height;
	new->weight = weight;
	new->type1 = type1;
	new->type2 = type2;
	new->next = NULL;
	new->status = FOUND;

	if(new->type1 == new->type2){
		new->type2 = NO_TYPE;
	}
   return new;
}

void printCurrentPkmn(PkmnList list) {
   // ADD YOUR CODE HERE

	if(list->head == NULL){
		printf("No Pokemon found. Get out there and find some Pokemon!");
		exit(1);
	}else{
	
		int i = 0;
		Pkmn cur = list->current;
		printf("Id: %03d\n", cur->id);
		if(cur->status == CAPTURED){
			printf("Name: %s\n", cur->name);
			printf("Height: %.2lfm\n", cur->height);
			printf("Weight: %.2lfkg\n", cur->weight);
			printf("Type: %s", getTypeString(cur->type1));
			if(cur->type2 != NO_TYPE){
				printf("/%s", getTypeString(cur->type2));
			}
			printf("\n");
		}
		
		else{
			printf("Name: ");
			while(i <strlen(cur->name)){
				printf("*");
				i++;
			}
			printf("\n");
			printf("Height: --\n");
			printf("Weight: --\n");
			printf("Type: -");
			if(cur->type2 != NO_TYPE){
				printf("-");
			}
			printf("\n");
		}
	}
}


PkmnList createPkmnList() {
   // ADD YOUR CODE HERE

	PkmnList list = malloc(sizeof(struct _list));
	if (list == NULL){
		printf("Out of Memory.\n");
		exit(1);
	}

	list->head = NULL;
	list->current = NULL;
	list->total = 0;

   return list;
}

void freePkmnList(PkmnList list) {
   // ADD YOUR CODE HERE
	assert(list != NULL);
	Pkmn cur = list->head;
	Pkmn prev = NULL;

	while(cur != NULL){
		prev = cur;
		cur = cur->next;
		free(prev);
	}

	free(list);

}

void addPkmnToList(PkmnList list, Pkmn pkmn) {
   // ADD YOUR CODE HERE

	assert(list != NULL);
	Pkmn cur = list->head;
	int status = FOUND;
	if(cur == NULL){
		list->head = pkmn;
		list->current = pkmn;
	}

	while(cur != NULL){
		if(cur->id == pkmn->id){
			status = CAPTURED;
		}
		cur = cur->next;
	}
	
	if(status == FOUND){
		cur->next = pkmn;
	}
	list->total++;
}

void printPkmnList(PkmnList list) {
   // ADD YOUR CODE HERE

	if(list->head == NULL){
		printf("No Pokemon found. Get out there and find some Pokemon!");
		exit(1);
	}
	int i = 0;
	Pkmn cur = list->head;

	while(cur != NULL){
		if(cur == list->current){
		printf("-->");
		}
		else{
		printf("   ");
		}
		printf("#%03d: ", cur->id);
		if(cur->status == CAPTURED){
			printf("%s", cur->name);
		}
		else{
			while(i < strlen(cur->name)){
				printf("*");
				i++;
			}
		}
		printf("\n");
		cur = cur->next;
	}
}

void nextPkmn(PkmnList list) {
   // ADD YOUR CODE HERE

	if(list->head == NULL){
		printf("No Pokemon found. Get out there and find some Pokemon!");
		exit(1);
	}

	else{
		Pkmn cur = list->current;
		if(cur->next != NULL){
			list->current = cur->next;
		}
	}	

}

void prevPkmn(PkmnList list) {
   // ADD YOUR CODE HERE

	if(list->head == NULL){
		printf("No Pokemon found. Get out there and find some Pokemon!");
		exit(1);
	}

	else{
		Pkmn cur = list->head;
		if(cur != list->current){
			while(cur->next != list->current){
				cur = cur->next;
			}
			list->current = cur;
		}
	}

}

void jumpToPkmn(PkmnList list, int id) {
   // ADD YOUR CODE HERE

	if(list->head == NULL){
		printf("No Pokemon found. Get out there and find some Pokemon!");
		exit(1);
	}

	Pkmn cur = list->head;
	while(cur->id != id){
		cur = cur->next;
	}
	list->current = cur;

}

void removePkmn(PkmnList list) {
   // ADD YOUR CODE HERE

	if(list->head == NULL){
		printf("No Pokemon found. Get out there and find some Pokemon!");
		exit(1);
	}

	Pkmn cur = list->current;
	if(cur == list->head){
		list->current = cur->next;
		list->head = list->current;
		if(cur->status == CAPTURED){
			list->countTotal--;
		}
		else{
			free(cur);
		}
	}	
	
	else{
		Pkmn prev = list->head;
		while(prev->next != list->current){
			prev = prev->next;
		}
		prev->next = cur->next;
		list->current = prev;
		if(cur->status == CAPTURED){
			list->countTotal--;
		}
		free(cur);
	}

	list->total--;
}

// Stage 3 Functions
void findPkmn(int seed, int factor, int numberOfNewPkmn, PkmnList list) {
   // ADD YOUR CODE HERE

	if(list->head == NULL){
		printf("No Pokemon found. Get out there and find some Pokemon!");
		exit(1);
	}

	srandom(seed);
	Pkmn cur;
	int i;
	while(i < numberOfNewPkmn){
		int find = rand()%factor+1;
		cur = list->head;
		while(cur != NULL){
			if(cur->id == find){
				if(cur->status == FOUND){
					cur->status = CAPTURED;
				}
			list->countTotal++;
			}
			cur = cur->next;
		}
		i++;
	}
}

int totalFound(PkmnList list) {
   // ADD YOUR CODE HERE

	if(list->head == NULL){
		printf("No Pokemon found. Get out there and find some Pokemon!");
		exit(1);
	}

   return list->countTotal;
}


// Stage 4 Functions
void addEvolution(PkmnList list, int pkmnId, int evolutionId) {
   // ADD YOUR CODE HERE
}

void showEvolutions(PkmnList list) {
   // ADD YOUR CODE HERE
}


// Stage 5 Functions
PkmnList getPkmnOfType(PkmnList list, int type) {
   // ADD YOUR CODE HERE

	PkmnList types = malloc(sizeof(struct _list));
	if(types == NULL){
		printf("Out of Memory. \n");
		exit(1);
	}

	Pkmn cur = types->head;

	while(cur != NULL){
		if(cur->type1 != type && cur->type2 != type){
			types->current = cur;
			removePkmn(types);
		}
	cur = cur->next;
	}
	types->current = types->head;

   return types;
}

PkmnList getFoundPkmn(PkmnList list) {
   // ADD YOUR CODE HERE

	PkmnList captured = malloc(sizeof(struct _list));
	if(captured == NULL){
		printf("Out of Memory. \n");
		exit(1);
	}

	captured = list;
	Pkmn cur = captured->head;
	while(cur != NULL){
		if(cur->status == FOUND){
			captured->current = cur;
			removePkmn(captured);
		}
		cur = cur->next;
	}

	Pkmn atm;
	Pkmn after;
	Pkmn before;
	Pkmn swap;
	Pkmn fin = NULL;

	while(fin != captured->head->next){
		atm = captured->head;
		before = atm;
		after = atm->next;
		
		while(atm != fin){
			if(atm->id > fin->id){
				if(atm == captured->head){
					swap = after->next;
					after->next = atm;
					atm->next = swap;
					captured->head = after;
					before = after;
				}
				else{
					swap = after->next;
					after->next = atm;
					atm->next = swap;
					before->next = after;
					before = after;
				}
			}
			else{
				before = atm;
				atm = atm->next;
			}
			after = atm->next;
			if(after == fin){
				fin = atm;
			}
		}
	}

	captured->current = captured->head;

   return captured;
}

PkmnList searchByName(PkmnList list, char text[]) {
   // ADD YOUR CODE HERE

	char *string = strdup(text);
	int i=0;
	while(string[i]){
		string[i] = tolower(string[i]);
		i++;
	}
	PkmnList search = malloc(sizeof(struct _list));
	if(search == NULL){
		printf("Out of Pokedex Memory.\n");
		exit(1);
	}
	search = list;
	Pkmn cur = search->head;
	while(cur != NULL){
		char *name = strdup(cur->name);
		i=0;
		while(name[i]){
			name[i] = tolower(name[i]);
			i++;
		}

		if(strstr(name, string)){
		}else{
			search->current = cur;
			removePkmn(search);
		}
		cur = cur->next;		
	}

	search->current = search->head;

    return search;
}

