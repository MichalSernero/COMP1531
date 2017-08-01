/*
 *  backToFront.c
 *  2013s1 Prac Exam
 *  UNSW comp1917
 *
 *  Created by INSERT YOUR NAME HERE
 *  Share freely CC-BY-3.0
 *
 */

// Complete this function and submit this file ONLY
// for the prac exam.  Do not change the other supplied
// as you will not be submitting them.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "backToFront.h"

nodePtr backToFront (nodePtr list) {
	nodePtr curr = list;
	nodePtr prev = NULL;
	if (curr == NULL || curr->next == NULL){
		return list;
	}
	
	while(curr->next != NULL){
		prev = curr;
		curr = curr->next;
	}
	
	curr->next = list;
	prev->next = NULL;
	
	return curr;
}



