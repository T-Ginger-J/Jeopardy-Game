/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2024, <Trent Jordan (100831853)>, <Loona Khan (100782789)>, <William Chamberlain (100846922)>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void) {
    // initialize each question struct and assign it to the questions array
    //questions = (question *) calloc(NUM_QUESTIONS, sizeof(question));
    question questionsinit[12] = {{"Data Structures", "The simplest data structure holding a collection of elements accessed by an index", "what is an array", 200, false},
                                {"Data Structures", "The Data Structure with branches stemming from a root", "what is a tree", 400, false},
                                {"Data Structures", "The acronym used to describe the order Stack data structures add and remove elements", "what is LIFO", 600, false},
                                {"Data Structures", "The big O time complexity describing adding, removing or searching in a hash tables", "what is 1", 800, false},
                                {"Operating Systems", "The macintosh uses this operating system", "what is MAC OS", 200, false},
                                {"Operating Systems", "The part of the operating system dedicated to selecting which proccess to execute", "what is the scheduler", 400, false},
                                {"Operating Systems", "The memory management technique that uses RAM and disk space to simulate additional memory", "what is virtual memory", 600, false},
                                {"Operating Systems", "The full name for the creator of the Linux operating system", "who is Linus Torvalds", 800, false},
                                {"Project Management", "A commonly used graphical representation of tasks and their timelines", "what is a gantt chart", 200, false},
                                {"Project Management", "The person responsible for defining project scope and ensuring deadlines are met", "who is project manager", 400, false},
                                {"Project Management", "The longest sequence of dependent tasks that determines the minimum time for the project", "what is the critical path", 600, false},
                                {"Project Management", "The acronym describing the cradle to coffin of developing software", "what is SDLC", 800, false}};
    memcpy(questions, questionsinit, sizeof(questions));
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
            if (questions[j * (NUM_QUESTIONS / NUM_CATEGORIES) + i].answered) {
                printf("| %*s ", catNameLength[j], "");
            } else {
                printf("| %*s ", catNameLength[j], questions[j * (NUM_QUESTIONS / NUM_CATEGORIES) + i]);
            }
        }
        printf("|\n%s\n", lineBreak);
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value) {
    if (already_answered(category, value)) {
        printf("Question already answered.\n");
    } else {
	    int index = find_index(category, value);
        assert(index != -1);
	    printf("Category: %s\nValue: %d\nQuestion: %s\n", questions[index].category, questions[index].value, questions[index].question);
    }
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer) {
	int index = find_index(category, value);
    assert(index != -1);
    // quit early if the lengths dont match
    if (strlen(answer) == strlen(questions[index].answer))
        return false;
    // since we don't want to force capitalization correctness, impement custom compare
    for (int i = 0; i < sizeof(answer) / sizeof(char); i++) {
        if (strncmp(answer, questions[index].answer, i) != 0 && strncmp(answer, questions[index].answer, i) != ('A' - 'a'))
            return false;
    }
    questions[index].answered = true;
    return true;
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
