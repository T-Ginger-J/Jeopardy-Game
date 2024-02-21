/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#ifndef PLAYERS_H_
#define PLAYERS_H_

#include <stdbool.h>

#define MAX_LEN 256

// Player struct for each player
typedef struct {
    char name[MAX_LEN];
    int score;
} player;

// Returns the index of the player with the accosiated name
extern int player_index(player *players, char *name);

// Returns true if the player name matches one of the existing players
extern bool player_exists(player *players, char *name);

// Go through the list of players and update the score for the 
// player given their name
extern void update_score(player *players, char *name, int score);

#endif /* PLAYERS_H_ */