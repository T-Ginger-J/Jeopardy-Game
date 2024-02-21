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
#include <stdbool.h>
#include "assert.h"
#include "players.h"

// Returns the index of the player with given name, returns -1 otherwise
int player_index(player *players, char *name) {
    for (int i = 0; i < sizeof(players) / sizeof(player); i++) {
        if (strcmp(players[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Returns true if the player name matches one of the existing players
bool player_exists(player *players, char *name) {
    return player_index(players, name) != -1;
}

// Go through the list of players and update the score for the 
// player given their name
void update_score(player *players, char *name, int score)
{
    assert(player_exists(players, name));
    players[player_index(players, name)].score += score;
}