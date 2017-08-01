#include <stdio.h>
#include <stdlib.h>
#include "Pkmn.h"

void printMenu();

int main(int argc, char * argv[]) {

   PkmnList list = createPkmnList();

   printMenu();
   char selection;
   scanf(" %c", &selection);
   while(selection != 'q') {
      if(selection == 'a') {
         // ADD YOUR CODE HERE (to add a new Pokemon to the list)
			int id;
			char name[PKMN_NAME_LENGTH];
			double height;
			double weight;
			int type1;
			int type2;

			printf("ID#: ");
			scanf("%d", &id);
			printf("Name: ");
			scanf("%s", name);	
			printf("Height: ");
			scanf("%lf", &height);
			printf("Weight: ");
			scanf("%lf", &weight);
			printf("Type 1: ");
			scanf("%d", &type1);
			printf("Type 2: ");
			scanf("%d", &type2);
				
			Pkmn pkmn = createPkmn(id, name, height, weight, type1, type2);
			addPkmnToList(list, pkmn);

      } else if (selection == 'p') {
         // ADD YOUR CODE HERE (to print the list of Pokemon)
			printPkmnList(list);
      } else if (selection == 'd') {
         // ADD YOUR CODE HERE (to display the details of the current Pokemon)
			printCurrentPkmn(list);
      // ADD YOUR CODE HERE (to add more commands which can execute)

	  } else if (selection == '>'){
			nextPkmn(list);
	  } else if (selection == '<'){
			prevPkmn(list);
	  } else if (selection == 'j'){
			int id;
			printf("Id: ");
			scanf("%d", &id);
			jumpToPkmn(list, id);
	  } else if (selection == 'r'){
			removePkmn(list);
	  } else if (selection == 'f'){
			int seed;
			int factor;
			int numberToFind;
			
			printf("Seed: ");
			scanf("%d", &seed);
			printf("Factor: ");
			scanf("%d", &factor);
			printf("Number to find: ");
			scanf("%d", &numberToFind);
			
			findPkmn(seed, factor, numberToFind, list);
	  } else if (selection == 'c'){
			int count = totalFound(list);
			printf("You have found %d Pokemon so far.\n", count);
	  } else if (selection == 'e'){
			int pkmnId;
			int evolutionId;
			printf("Id of original Pokemon: ");
			scanf("%d", &pkmnId);
			printf("Id of evolution: ");
			scanf("%d", &evolutionId);
			addEvolution(list, pkmnId, evolutionId);
	  } else if (selection == 's'){
			showEvolutions(list);
	  }	else if (selection == '1'){
			int type;
			printf("Type: ");
			scanf("%d", &type);
			PkmnList types = getPkmnOfType(list, type);
			printPkmnList(types);
			freePkmnList(types);
	  }	else if (selection == '2'){
			PkmnList founds = getFoundPkmn(list);
			printPkmnList(founds);
	  } else if(selection == '3'){
			printf("Enter pokemon name: ");
			char text[PKMN_NAME_LENGTH];
			scanf("%s", text);
			PkmnList search = searchByName(list, text);
	 		printPkmnList(search);
	  }	
      printMenu();
      scanf(" %c", &selection);
   }

   freePkmnList(list);

   return EXIT_SUCCESS;
}

void printMenu() {

   printf("a - Add a Pokemon to the list\n");
   printf("p - Print list\n");
   printf("d - Display details of the current Pokemon\n");
   printf("> - Move to the next Pokemon");
   printf("< - Move to the previous Pokemon");
   printf("j - Jump to a specific Pokemon");
   printf("r - Remove the currrent Pokemin");
   printf("f - Find Pokemon");
   printf("c - Count the number of Pokemon which have been found");
   printf("e - Add an evolution to a Pokemon");
   printf("s - Show the evolutions of the current Pokemon");
   printf("q - Quit\n");
}
