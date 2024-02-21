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
void display_categories(void) {
    int catNameLength[NUM_CATEGORIES];
    int spacer = 1;
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        catNameLength[i] = strlen(categories[i]);
        spacer += 3 + catNameLength[i];
    }
    char lineBreak[spacer + 1];
    lineBreak[spacer] = '\0';
    memset(lineBreak, '-', spacer);
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        printf("| %s ", categories[i]);
    }
    printf("|\n%s\n", lineBreak);
    for (int i = 0; i < NUM_QUESTIONS / NUM_CATEGORIES; i++) {
        for (int j = 0; j < NUM_CATEGORIES; j++) {
            printf("| %*s ", catNameLength[j], questions[j * (NUM_QUESTIONS / NUM_CATEGORIES) + i]);
        }
        printf("|\n%s\n", lineBreak);
    }
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
bool already_answered(char *category, int value) {
    // lookup the question and see if it's already been marked as answered
    int index = find_index(category, value);
    assert(index != -1);
    return questions[index].answered;
}

int find_index(char *category, int value) {
	for (int i = 0; i < NUM_CATEGORIES; i++) {
        if (strcmp(category, categories[i])) {
            for (int j = 0; j < NUM_QUESTIONS / NUM_CATEGORIES; i++) {
                if (questions[i * 4 + j].value == value) {
                    return i * 4 + j;
                }
            }
        }
    }
	return -1;
}
