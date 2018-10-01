#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

using namespace std;

#define KO_HEALTH 100
#define DEAD_HEALTH 115
#define MAXTEXT 256

int p1hurt = 0;
int p2hurt = 0;
char p1name[MAXTEXT];
char p2name[MAXTEXT];

extern "C" void win();

void win(char *player)
{
    printf("Player %s wins the game.\n", player);
    exit(0);
}

int generateRandomHit()
{
    return rand() % 10 + 10;
}

int checkMovement(char *movement)
{
    if (!strcmp(movement, "block")) {
        printf("You Used %s. Next player's turn. \n", movement);
        return 1;
    } else if (!strcmp(movement, "hit")) {
        printf("You Used %s. Next player's turn. \n", movement);
        return 2;
    } else {
        printf(movement);
        printf(" is not permitted.\n");
        return 3;
    }
}

int main()
{
    int counter = 0;
    int points = 0;
    int res;
    char op[MAXTEXT];
    printf("Welcome to MathFighter\n");
    printf("Rules:\nEach round you can 'hit' or 'block' your opponent.\n");
    printf("You will be giving a number of points to use on your opponent per round.\n");
    printf("You win when your opponent is knocked-out (More than 100 points).\n");
    printf("Be careful of not hitting them too much (Less than 115 points) \n");
    printf("Please enter Player 1 name:\n");
    cin.getline(op, MAXTEXT);
    printf(op);
    cin.getline(p1name, MAXTEXT);
    printf("Please enter Player 2 name:\n");
    cin.getline(p2name, MAXTEXT);

    do {
        if (counter % 2 == 0) {
            points = generateRandomHit();
            printf(p1name);
            printf(", you have %d points available.\n", points);
            printf("Your move: ");
            cin.getline(op, MAXTEXT);
            res = checkMovement(op);
            if (res == 1)
                p2hurt -= points;
            if (res == 2)
                p2hurt += points;
            printf("You have made %d points of damage.\n", p2hurt);

        } else {
            points = generateRandomHit();
            printf(p2name);
            printf(", you have %d points available.\n", points);
            printf("Your move: ");
            cin.getline(op, MAXTEXT);
            res = checkMovement(op);
            if (res == 1)
                p1hurt -= points;
            if (res == 2)
                p1hurt += points;
            printf("You have made %d points of damage.\n", p1hurt);

        }
        counter++;

        if (p1hurt > KO_HEALTH && p1hurt < DEAD_HEALTH) {
            win(p1name);
        }

        if (p2hurt > KO_HEALTH && p2hurt < DEAD_HEALTH) {
            win(p2name);
        }

    } while (true);


}
