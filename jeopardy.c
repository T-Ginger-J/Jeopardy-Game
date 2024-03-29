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
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char tokens[][100]) {
    char *token = strtok(input, " ");
    //printf("%s\n", token);
    strcpy(tokens[0], token);
    int i=1;
    while (token != NULL) {
        token = strtok(NULL, " ");
        if (token == NULL) break;
        //printf("%s\n", token);
        strcpy(tokens[i], token);
        i++;
    }
}

void sort(player *players, int num_players) { // bubble sort
    int i, j;
    int swapped;
    for (i =0; i< num_players - 1; i++) {
        swapped = 1;
        for (j = 0; j < num_players - i-1; j++) {
            if ((*(players+j)).score  < (*(players+j+1)).score) {
                player temp = *(players+j);
                *(players+j) = *(players+j+1);
                *(players+j+1) = temp;
                swapped = 0;
            }
        }

        if (swapped == 1) break;
    }
}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players) {
    sort(players, num_players);

    printf("Player scores\n");
    for (int i=0; i < num_players; i++) {
        player p = *(players+i);
        printf("player %s score: %d\n", p.name, p.score);
    }
}

bool unansweredQuestions() {
    for (int i = 0; i < sizeof(questions)/sizeof(question); i++) {
        if (!questions[i].answered)
            return true;
    }
    return false;
}


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };
    char tokens[][100]= {};

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    printf("List 4 players\n");
    for (int i =0; i< 4; i++) {
        printf("player %d: ", i+1);
        fgets(buffer, BUFFER_LEN, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // clears trailing \n

        // creates the player
        player p;
        strcpy(p.name, buffer);
        p.score = 0;
        players[i] = p;

        strcpy(buffer, ""); // empties buffer
    }
    show_results(players, NUM_PLAYERS);

    // Perform an infinite loop getting command input from users until game ends
    while (true)
    {
        if (!unansweredQuestions)
            break;
        for (int i = 0; i < 4; i++) {
            display_categories();
            printf("%s please select a category and value: ", players[i].name);
            buffer[strcspn(buffer, "\n")] = 0; // clears trailing \n
            tokenize(buffer, &tokens);
            display_question(tokens[0], atoi(tokens[1]));
            printf("What is your answer: ");
            char ans[MAX_LEN];
            scanf("%[^\n]", ans);
            bool correct = valid_answer(tokens[0], atoi(tokens[1]), ans);
            if (correct) {
                printf("CORRECT!\n");
                update_score(players, players[i].name, atoi(tokens[1]));
            } else {
                printf("INCORRECT!");
                update_score(players, players[i].name, -1 * atoi(tokens[1]));
            }
        }
        // Execute the game until all questions are answered
    }
    // Display the final results and exit
    show_results(players, NUM_PLAYERS);

    return EXIT_SUCCESS;
}
