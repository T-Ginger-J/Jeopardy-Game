/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
	find_index(category, value);
	
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
	find_index(category, value);
   
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    find_index(category, value);
    return false;
}

int find_index(char *category, int value, char *answer)
{
	int index = (value / 200) - 1;
	if (strcomp(category, "category1") == 0){
	} else if (strcomp(category, "category2") == 0){
		index += 4;
	} else if (strcomp(category, "category3") == 0){
		index += 8;
	} else {
		index = -1;
	}
	return index;
	
}
