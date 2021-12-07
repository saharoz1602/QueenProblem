#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int board[8] = { 0,0,0,0, 0,0,0,0 };

int count = 0;

void printBoard() {
    int i, j;
    printf("--------------\n");
    printf("|Solution %d:|\n", count);
    printf("--------------\n");

    for (j = 0; j < 8; ++j)
        printf("+---");
    printf("+\n");

    for (i = 0; i < 8; ++i) {

        for (j = 0; j < board[i]; ++j)
            printf("|   ");
        printf("| Q ");
        j++;
        for (; j < 8; ++j)
            printf("|   ");
        printf("|\n");

        for (j = 0; j < 8; ++j)
            printf("+---");
        printf("+\n");
    }
    printf("\n\n");
}

int valid(int i, int j) {
    int diagPlus = i + j, diagMinus = i - j;

    int i1;
    for (i1 = 0; i1 < i; ++i1) {
        int j1 = board[i1];
        if (j == j1 || i1 + j1 == diagPlus || i1 - j1 == diagMinus)
            return 0;
    }
    return 1;
}

void queens(int i) {
    int flag = 0;
    if (i == 8) {
        ++count;
        printBoard();
        return;
    }
    int j;
    for (j = 0; j < 8; ++j) {
        if (valid(i, j)) {
            board[i] = j;
            queens(i + 1);
        }
    }

}

void solve8queens() {
    queens(0);
}

int main() {
    printf("---------------------------------------------------------------------------------------\n");
    printf("|All the options to put eight queens on one chess board that no one attaks the others.|\n");
    printf("---------------------------------------------------------------------------------------\n");
    solve8queens();
    return 0;
}